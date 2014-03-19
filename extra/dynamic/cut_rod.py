def cut_rod(price, n, count):
    if n <= 0:
        return 0, count
    max_val = 0
    c = []
    for i in xrange(0, n):
        u, c_ = cut_rod(price, n - 1 - i, count + 1)
        c.append(c_)
        max_val = max(max_val, price[i] + u)
    return max_val, sum(c)

def cut_rod_d(price, n):
    values = [0 for i in xrange(n + 1)]
    count = 0
    for j in xrange(n):
        max_val = 0
        for i in xrange(0, j + 1):
            count += 1
            max_val = max(max_val, price[i] + values[j - i])
        values[j + 1] = max_val 
    return values[n], count

if __name__ == '__main__':
    arr = [1, 5, 8, 9, 10, 17, 17, 20]
    print cut_rod(arr, len(arr), 0)
    print cut_rod_d(arr, len(arr))

