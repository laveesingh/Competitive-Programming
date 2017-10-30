import random

def case():
    n = random.randint(1, 20)
    print n
    for i in xrange(n):
        print random.randint(1, 100),
    print

t = random.randint(1, 5)
print t
for _ in xrange(t):
    case()
