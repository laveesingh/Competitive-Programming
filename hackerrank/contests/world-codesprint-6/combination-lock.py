'''input
1 2 9 5 7
1 3 2 0 7
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

a = ai()
b = ai()
ans = 0
for i in xrange(len(a)):
	diff = abs(a[i]-b[i])
	ans += min(diff, 10-diff)

print ans