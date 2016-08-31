'''input
3
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

n = ii()

store = []

for i in xrange(n):
	for j in xrange(n):
		if i != j:
			k = n-i-j
			if k != i and k != j:
				store.append((i,j,k))

X = [0]*n
Y = [0]*n
Z = [0]*n
final =  []

for s in store:
	i,j,k = s
	if not (X[i] or Y[j] or Z[k]):
		X[i] = 1
		Y[j] = 1
		Z[k] = 1
		final.append((i,j,k))

print len(final)
for s in final:
	for t in s:
		print t,
	print
