import random

def case():
    n = random.randint(1, 10**2)
    print n 
    a = [random.randint(1, 10**3) for i in xrange(n)]
    for s in a:
        print s,
    print
    q = random.randint(1, 10**1)
    print q
    for _ in xrange(q):
        a = random.randint(1, n)
        b = random.randint(a, n)
        x = random.randint(1, 10**2)
        y = random.randint(x, 10**2)
        print a, b, x, y

case()