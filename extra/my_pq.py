from heapq import heappush, heappop, heapify

class PQ(object):

    def __init__(self):
        self.h = []

    def offer(self, key, data):
        heappush(self.h, (key, data,))

    def take(self):
        return heappop(self.h)

    def is_empty(self):
        return len(self.h) <= 0

    def decrease_key(self, key, new_key, data=None):
        for i in xrange(len(self.h)):
            u, v = self.h[i]
            if u == key and ((data is not None and data == v) or data is None):
                self.h[i] = (new_key, v,)
        heapify(self.h) 

if __name__ == '__main__':
    import random
    pq = PQ()
    data = [(random.randint(10, 100), random.randint(100, 1000)) for i in range(10)]
    count = 0
    hu, hv = None, None
    for k, v in data:
        count += 1
        if count == 3:
            hu = k
            hv = v
        pq.offer(k, v)
    pq.decrease_key(hu, 20, hv)
    print hu, hv
    while not pq.is_empty():
        print pq.take()


