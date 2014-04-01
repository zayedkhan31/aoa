import random

def floydwarshall(vertices, edges):

    distance = {}
    for v in xrange(len(vertices)):
        if distance.get(v, None) is None:
            distance[v] = {}
            for i in xrange(len(vertices)):
                distance[v][i] = 0
        distance[v][v] = 0
    
    for e in edges:
        distance[e[0]][e[1]] = e[2]
        distance[e[1]][e[0]] = e[2]
    
    for k in xrange(1, len(vertices)):
        for i in xrange(1, len(vertices)):
            for j in xrange(1, len(vertices)):
                if distance[i][j] > distance[i][k] + distance[k][j]:
                    distance[i][j] = distance[i][k] + distance[k][j]
    print "\nDistance" 
    print "\n".join([" ".join(["%4d" % distance[v][u] for u in distance[v].keys()]) for v in distance.keys()])
    

def display(vertices, edges):
    graph = [[0 for j in xrange(len(vertices))] for i in xrange(len(vertices))]
    for edge in edges:
        graph[edge[0]][edge[1]] = edge[2]
        graph[edge[1]][edge[0]] = edge[2]
    print "\n".join([" ".join(["%4d" % u for u in v]) for v in graph])

if __name__ == '__main__':
    vertices = [x for x in range(5)]
    edges = []
    for i in xrange(10):
        edges.append((random.randint(0, 4), random.randint(0, 4), random.randint(2, 10),))
    display(vertices, edges)
    floydwarshall(vertices, edges)
