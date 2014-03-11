from my_pq import PQ
import random, sys

source = 0

def generate_data():
    vertexes = [i for i in range(10)]
    cost = [[0 for j in vertexes] for i in vertexes]
    
    for i in xrange(0, len(cost)):
        cost[i][i] = 0
        for j in xrange(i + 1, len(cost)):
            cost[i][j] = cost[j][i] = random.randint(1, 10)
    return vertexes, cost

def dijkstra(source, vertex, cost):
    dist = {}
    previous = {}
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
            if cost[u][v] == 0:
                continue
            alt = dist[u] + cost[u][v]
            if alt < dist[v]:
                old_value = dist[v]
                dist[v] = alt 
                previous[v] = u 
                pq.decrease_key(old_value, alt, v)
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
