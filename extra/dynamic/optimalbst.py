import random, sys 

class Node:
    def __init__(self, root, left, right):
        self.root = root 
        self.left = left
        self.right = right

def opt_cost(freq, i, j):
    if j < i:
        return 0, None
    if (i == j): 
        n = Node(i, None, None)
        return freq[i], n
    freq_sum = sum([freq[k] for k in xrange(i, j + 1)])
    min_ = sys.maxint 
    root, n = None, None
    for r in xrange(i + 1, j):
        c1, n1 = opt_cost(freq, i, r - 1) 
        c2, n2 = opt_cost(freq, r + 1, j)
        cost = c1 + c2
        if cost < min_:
            min_ = cost 
            root = r
            n = Node(root, n1, n2)
    return min_ + freq_sum, n

def opt_cost_d(freq, n):
    m = [[0 for u in xrange(n)] for v in xrange(n)]
    r_ = [[0 for u in xrange(n)] for v in xrange(n)]

    for i in xrange(n):
        m[i][i] = freq[i]
   
    for l in xrange(2, n + 1):
        for i in xrange(n - l + 1):
            j = i + l -1
            m[i][j] = sys.maxint 
            for r in xrange(i, j + 1):
                c = m[i][r - 1] if r > i else 0 + m[r + 1][j] if r < j else 0 + sum(freq[i:j + 1])
                if c < m[i][j]:
                    r_[i][j] = r
                    m[i][j] = c

    print "M\n"
    print "\n".join(["%d: %s" % (ix, ' '.join(["%4s" % str(i) for i in v])) for ix, v in enumerate(m)])
    print "R\n"
    print "\n".join(["%d: %s" % (ix, ' '.join(["%4s" % str(i) for i in v])) for ix, v in enumerate(r_)])
    return m[0][n - 1]

if __name__ == '__main__':
    keys = set([random.randint(0, 25) for i in xrange(10)])
    keys = [i for i in keys]
    freq = [random.randint(0, 25) for i in xrange(len(keys))]
    print 'I:', ''.join(["%4d" % i for i in xrange(len(keys))])
    print 'F:', ''.join(["%4d" % i for i in freq])
    print 'K:', ''.join(["%4d" % i for i in keys])
    cost, root = opt_cost(freq, 0, len(keys) - 1)    
    queue = []
    queue.append(root)
    while len(queue) > 0:
        n = queue.pop(0)
        if n is None:
            continue
        print n.root, "[%s]" % str(keys[n.root]) if n else '_', n.left.root if n.left else '_', n.right.root if n.right else '_'
        if n.left:
            queue.append(n.left)
        if n.right:
            queue.append(n.right)
