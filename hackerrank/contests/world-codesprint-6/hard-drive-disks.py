'''input
5 2
6 7
-1 1
0 1
5 2
7 3
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

n, k = ai()

prime = [0]*n
sec = [0]*n

for i in xrange(n):
	x, y = ai()
	prime[i] = x
	sec[i] = y

left = min(min(prime), min(sec))
right = max(max(prime), max(sec))
portion = range(left, right+1)
ans = sys.maxint
for temp in itertools.combinations(portion, k):
	comps = list(temp)
	wire = 0
	for i in xrange(n):
		dist = sys.maxint
		for j in xrange(k):
			dist = min(dist, abs(comps[j]-prime[i])+abs(comps[j]-sec[i]))
		wire += dist
	ans = min(ans, wire)
print ans
