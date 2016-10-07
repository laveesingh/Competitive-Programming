from fractions import gcd
from collections import defaultdict

n = input()
# store = defaultdict(int)
ans = 0
for i in xrange(2, n/3+1):
    for j in xrange(i+1,n/2 + 1):
        if (gcd(i,j) == 1):
            # store[i*j] += 1
            if i*j <= n:
                print i,j
                ans += 1

print ans