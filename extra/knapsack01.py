import random

def knapsack_expo(W, w, v, n, counter):
    counter += 1
    if n==0 or W==0:
        return 0, counter
    if w[n - 1] > W:
        return knapsack_expo(W, w, v, n - 1, counter)
    else:
        x, c1 = knapsack_expo(W - w[n - 1], w, v, n - 1, counter) 
        y, c2 = knapsack_expo(W, w, v, n - 1, counter)
        return max(x + v[n - 1], y), c1 + c2 


def knapsack_dyna(W, w, v, n):
    m = [[0 for i in xrange(W)] for j in xrange(n)]
    counter = 0
    for i in xrange(0, n):
        for j in xrange(W):
            counter += 1
            if i == 0 or j == 0:
                m[i][j] = 0
            elif w[i] > j:
                m[i][j] = m[i-1][j]
            else:
                m[i][j] = max(v[i] + m[i - 1][j - w[i-1]], m[i-1][j])
    print "\n".join(["%d: %s" % (ix, ' '.join([str(i) for i in v])) for ix, v in enumerate(m)])
    return m[n - 1][W - 1], counter

if __name__ == '__main__':
    w = [random.randint(1, 10) for i in xrange(10)]
    v = [random.randint(1, 10) for i in xrange(10)]
    n = 10
    W = 25
    print W, n
    print "W:", w
    print "V:", v
    print knapsack_expo(W, w, v, n, 0)
    print knapsack_dyna(W, w, v, n)
