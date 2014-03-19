from functools import wraps 

def memoize(func):
    data = {}
    @wraps(func)
    def decorated(*args, **kwargs):
        if args[0] not in data.keys():
            d = func(*args, **kwargs)
            data[args[0]] = d
        return data[args[0]]

    return decorated

@memoize
def fibonacci_normal(N):
    if N == 0 or N ==1:
        return 1
    return fibonacci_normal(N - 1) + fibonacci_normal(N - 2)

def dynamic_fibonacci(N):
    i, j = 1, 1
    for k in xrange(2, N + 1):
        i, j = i + j, i 
    return i

if __name__ == '__main__':
    for value in xrange(10):
        print fibonacci_normal(value), dynamic_fibonacci(value)
