import sys

def normal_chain(p):
    if len(p) < 3:
        print p
        return 0
    if len(p) == 3:
        return p[0] * p[1] * p[2] 

    val = sys.maxint 
    for i in xrange(1, len(p)):
        for j in xrange(i + 1, len(p)):
            for k in xrange(i + 1, j): 
                print i, k, j
                val = min(val, 
                        normal_chain(p[i - 1: k + 1]) + 
                        normal_chain(p[k - 1: j + 1]) + 
                        p[i - 1] * p[k] * p[j])
    return val 

def dynamic_chain(p, n):
    dynamic = dict([(i + 1, dict([(j + 1, sys.maxint) for j in xrange(n)])) for i in xrange(n)])
    for i in xrange(1, n):
        dynamic[i][i] = 0
        j = i + 1
        if j >= n:
            continue
        dynamic[i][j] = p[i - 1] * p[i] * p[j]

    for l in xrange(2, n):
        for i in xrange(1, n):
            j = i + l - 1 
            if j >= n + 1: continue
            
            for k in xrange(i, j):
                dynamic[i][j] = min(dynamic[i][j], dynamic[i][k] + dynamic[k][j] + p[i - 2] * p[k - 1] * p[j - 1])
    #print "\n".join([str([dynamic[v][u] for u in dynamic[v]]) for v in dynamic])
    return dynamic[1][n - 1]



if __name__ == '__main__':
    p = [10, 4, 5, 20, 43, 34]
    print normal_chain(p)
    print dynamic_chain(p, len(p))
