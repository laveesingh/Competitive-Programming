import random

def case():
    n = random.randint(1, 5)
    a = [random.randint(-2, 2) for i in xrange(n)]
    print n
    for s in a:
        print s,
    print

t = random.randint(10, 20)
print t
for _ in xrange(t):
    case()

