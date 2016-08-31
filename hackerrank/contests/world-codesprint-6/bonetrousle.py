'''input
5
12 8 3
10 3 3
9 10 2
15 7 2
21 20 1
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

sigma = lambda n: (n*(n+1))/2

# def solveodd(n, k, b):
# 	mid = n/b
# 	us = sigma(mid+b/2)

# 	## Bounds must be bounded
# 	if (mid+b/2) > k:
# 		return [-1]
# 	if (mid-b/2-1) < 0:
# 		return [-1]
# 	#######################

# 	ls = sigma(mid-b/2-1)
# 	Sum = us-ls
# 	portion = range(mid-b/2, mid+b/2+1)
# 	if Sum == n:
# 		return portion
# 	if portion[-1] >= k:
# 		return [-1]
# 	diff = n-Sum
# 	for i in xrange(len(portion)-diff, len(portion)):
# 		portion[i] += 1
# 	return portion

def solve(n, k, b):
	if b == 1:
		if n <= k:
			return [n]
		return [-1]
	if sigma(b) > n:
		return [-1]
	if sigma(k)-sigma(k-b-1) < n:
		return [-1]

	lo = 1
	hi = 10 ** 20
	x = 1
	while (lo <= hi):
		if x == (lo+hi)/2:
			break
		x = (lo+hi)/2
		csum = sigma(x+b-1)-sigma(x-1)
		# print "x:",x,"csum:",csum
		if csum < n:
			lo = x
		else:
			hi = x-1
	portion = range(x,x+b)
	if portion[-1] > k:
		return [-1]
	csum = sigma(x+b-1)-sigma(x-1)
	if csum == n:
		return portion
	if csum > n:
		return [-1]
	if portion[-1] >= k:
		return [-1]
	diff = n-csum
	for i in xrange(len(portion)-diff, len(portion)):
		portion[i] += 1
	if max(portion) > k:
		return [-1]
	# try:
	# 	portion[-diff] = portion[-1]+1
	# except IndexError:
	# 	return [-1]
	return portion

for _ in xrange(ii()):
	n, k, b = ai()
	ans = solve(n,k,b)
	# print "sum:",sum(ans),": ",
	for s in ans[:-1]:
		print s,
	print ans[-1]

