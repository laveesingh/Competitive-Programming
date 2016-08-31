'''input
2
2
112 42 83 119
56 125 56 49
15 78 101 43
62 98 114 108
1
1 2 
3 4
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

t = ii()
for _ in xrange(t):
	n = ii()
	a = []
	for i in xrange(2*n):
		a.append(ai())
	ans = 0
	for i in xrange(n):
		for j in xrange(n):
			x, y, z, w = a[i][j], a[2*n-i-1][j], a[i][2*n-j-1],a[2*n-i-1][2*n-j-1]
			# print x, y, z, w
			ans += max(x,y,z,w)
	print ans