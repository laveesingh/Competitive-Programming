import random

def case():
    q = random.randint(1,100000)
    a = []
    for i in xrange(random.randint(1,10000)):
        a.extend([random.randint(1,30)]*random.randint(1,15))
    n = len(a)
    print n,q
    for s in a: print s,
    print
    for i in xrange(q):
        x = random.randint(1,n)
        y = random.randint(x,n)
        z = random.randint(1,6)
        print x,y,z

t = 1
print t
for _ in xrange(t):
    case()
