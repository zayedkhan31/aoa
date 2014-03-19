from my_pq import PQ
import random, sys

source = 0

def generate_data():
    vertexes = [i for i in range(5)]
    cost = [[0 for j in vertexes] for i in vertexes]
    
    for i in xrange(0, len(cost)):
        cost[i][i] = 0
        for j in xrange(i + 1, len(cost)):
            if random.randint(0, 10) > 5: continue
            r = random.randint(1, 10)
            cost[i][j] = r 
            cost[j][i] = r
    return vertexes, cost

def dijkstra(source, vertex, cost):
    dist = {}
    previous = {}
    visited = set([])
    dist[source] = 0
    pq = PQ()
    for v in vertex:
        if v is not source:
            dist[v] = sys.maxint 
        previous[v] = None
        pq.offer(dist[v], v)

    while not pq.is_empty():
        x, u = pq.take() 
        for v in xrange(0, len(cost[u])):
            if cost[u][v] == 0 or (u, v,) in visited or (v, u,) in visited:
                continue 
            visited.add((u, v,))
            alt = dist[u] + cost[u][v]

            print "Checking %d: %d {%d}[%d, %d, %d]" % (u, v, alt, dist[u], dist[v], cost[u][v])
            if alt < dist[v]:
                pq.decrease_key(dist[v], alt, v)
                dist[v] = alt 
                previous[v] = u 
    return previous 



def print_data(vertexes, cost, source=None, previous=None):
    print "Vertex\n-----\n", vertexes
    print "\nCost"
    print "...", " ".join(["%4d" % u for u in vertexes])
    print '-'.join(['' for i in xrange(56)])
    for i in xrange(0, len(cost)):
        print "%d |" % i, " ".join(["%4d" % u for u in cost[i]]),"|"
    if source is None or previous is None:
        return 
    for i in vertexes:
        recursive_path(source, i, previous)

def recursive_path(source, destination, previous):
    path = []
    od = destination
    while destination is not source:
        path.append(destination)
        destination = previous[destination]
    print od, source, path, sum(path)

if __name__ == '__main__':
    v, c = generate_data()
    val = dijkstra(0, v, c)
    print_data(v, c, 0, val)
