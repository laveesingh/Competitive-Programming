import random

def case():
    n = random.randint(1, 8)
    print n
    for i in xrange(n):
        print random.randint(-20, 20),
    print

t = random.randint(1, 5)
print t
for i in xrange(t):
    case()
