import random

def case(n):
    N = random.randint(1, 10)
    k = random.randint(1, N)
    print N, k, 10
    for _ in xrange(N):
        x = random.randint(1, n)
        y = random.randint(x, n)
        print x, y
    for _ in xrange(10):
        x = random.randint(1, n)
        y = random.randint(x, n)
        print x, y

case(10)
