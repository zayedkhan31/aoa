import itertools, math

### Native Solution

def tsp_naive_solve(d):
    btl, best_tour = min((tour_len(t, d), t) for t in itertools.permutations(range(0, len(d))))
    return best_tour

def tour_len(t, d):
    total_distance = 0
    for i in xrange(len(t)):
        if i + 1 == len(t):
            break
        total_distance += d[t[i]][t[i + 1]]
    return total_distance

### Dynamic Recursive

### Dynamic Bottom Up approach

def solve_tsp_dynamic(all_distances):
    #calc all lengths
    #all_distances = [[length(x,y) for y in points] for x in points]
    #initial value - just distance from 0 to every other point + keep the track of edges
    A = {(frozenset([0, idx+1]), idx+1): (dist, [0,idx+1]) for idx,dist in enumerate(all_distances[0][1:])}
    print "A", A
    cnt = len(all_distances)
    for m in range(2, cnt):
        B = {}
        print "Initial S's", [frozenset(C) | {0} for C in itertools.combinations(range(1, cnt), m)]
        for S in [frozenset(C) | {0} for C in itertools.combinations(range(1, cnt), m)]:
            print "S", S
            for j in S - {0}:
                #this will use 0th index of tuple for ordering, the same as if key=itemgetter(0) used
                values = [
                            (
                                A[(S-{j},k)][0] + all_distances[k][j], 
                                A[(S-{j},k)][1] + [j]
                            ) for k in S if k != 0 and k!=j
                        ]
                print "\t", "J", j, "Values", values
                B[(S, j)] = min(values)  
            print "\tB", B

        A = B
    res = min([(A[d][0] + all_distances[0][d[1]], A[d][1]) for d in iter(A)])
    return res[1]

def length(x,y): return math.sqrt(pow((x[0]-y[0]),2) + pow((x[1]-y[1]),2))

if __name__ == '__main__':
    edges = [
                [0, 3, 2, 1],
                [1, 0, 4, 4],
                [3, 2, 0, 3],
                [1, 2, 1, 0]
            ]
    print tsp_naive_solve(edges)
    #print solve_tsp_dynamic(edges)
