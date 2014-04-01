import sys

def bellman(edges, source):

    distance = {}
    predecessor = {}
    for v in edges.keys():
        if v is source:
            distance[v] = 0
        else:
            distance[v] = sys.maxint
        predecessor[v] = None

    for k in edges.keys():
        for i in edges.keys():
            for j in edges[i].keys():
                if edges[i][j] == 0 or i == j: 
                    continue
                alpha = distance[i] + edges[i][j]
                #print i, j, alpha, distance[j]
                if alpha < distance[j]:
                    distance[j] = alpha 
                    predecessor[j] = i
        print distance
    
    for u in edges.keys():
        for v in edges[u].keys():
            if edges[u][v] == 0: continue
            if distance[u] + edges[u][v] < distance[v]:
                raise Exception("There is a negetive cycle")

    print "Distance:", "[%s]" % ", ".join(["%s -> %s" % (u, v) for u, v in distance.iteritems()])
    print "Predecessor:", "[%s]" % ", ".join(["%s -> %s" % (u, v) for u, v in predecessor.iteritems()])

def display(edges):
    graph = [[edges[u][v] for v in xrange(1, len(edges[u]) + 1)] for u in xrange(1, len(edges.keys()) + 1)]
    print "\n".join([" ".join(["%4d" % u for u in v]) for v in graph])

if __name__ == '__main__':
    vertices = [x for x in range(1, 6)]
    edges = {
                1: {1: 0, 2: 0, 3: 6, 4: 3, 5: 0},
                2: {1: 3, 2: 0, 3: 0, 4: 0, 5: 0},
                3: {1: 0, 2: 0, 3: 0, 4: 2, 5: 0},
                4: {1: 0, 2: 1, 3: 1, 4: 0, 5: 0},
                5: {1: 0, 2: 4, 3: 0, 4: 2, 5: 0}
        }
    display(edges)
    bellman(edges, 5)
