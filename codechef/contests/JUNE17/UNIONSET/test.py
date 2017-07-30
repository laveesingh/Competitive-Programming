import random

def case():
    n = random.randint(1, 500)
    k = random.randint(1, 500)
    print n, k
    rem = n
    total = 1000
    avg_dist = total / rem
    for i in xrange(n):
        ni = random.randint(1, avg_dist)
        ni = min(k, ni)
        pos_array = range(1, k+1)
        random.shuffle(pos_array)
        pos_array = pos_array[:ni]
        print ni,
        for s in pos_array:
            print s,
        print
        total -= ni
        rem -= 1
        if rem > 0:
            avg_dist = total / rem

t = 10

print t
for i in xrange(t):
    case()