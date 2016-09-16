'''input
6 3
1 1 1 1 1 5
1 1 1 1 1 5
1 1 1 1 1 5
1 1 1 1 1 5
1 1 1 1 1 5
1 1 1 1 1 5
'''

import os, sys, collections, itertools, pprint, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

n,p = None, None

def fits(mid, Sum, V):
	'''Returns 1 if need to increase sum i.e., lo = mid+1
	Returns 2 if need to decrease the sum i.e., hi = mid'''
	del V[:]
	cursum = 0
	for j in xrange(n):
		if Sum[j] > mid: return 1
		if cursum+Sum[j] > mid:
			V.append(j)
			cursum = Sum[j]
		else:
			cursum += Sum[j]
	if len(V) > p-1: return 1
	if len(V) < p-1: return 3
	return 2

def fits2(mid, FM, V):
	cursum = [0]*p
	del V[:]
	for i in xrange(len(FM)):
		for j in xrange(len(FM[0])):
			if FM[i][j] > mid: return 1
	for i in xrange(n):
		for j in xrange(p):
			if cursum[j]+FM[j][i] > mid:
				V.append(i)

				cursum = [FM[k][i] for k in xrange(p)]
				break
			else:
				cursum[j] += FM[j][i]
	if len(V) < p-1:
		return 3 # hi = mid-1
	if len(V) > p-1:
		return 1
	return 2


n, p = ai()
a = []
for _ in xrange(n):
	a.append(ai())

rsum = [sum(a[i]) for i in xrange(n)]

lo, mid, hi = 0, 0, 10**18
H, V = [], []
while lo <= hi:
	if mid == (lo+hi)/2: break
	mid = (hi+lo)/2
	ans = fits(mid, rsum, H)
	# print "H:",H
	if ans == 2: hi = mid
	elif ans == 3: hi = mid-1
	else: lo = mid+1

if lo > hi:
	lo, hi = hi, lo
if (fits(lo, rsum, H) == 2):
	None
else:
	fits(hi, rsum, H)

FM = [[0 for i in xrange(n)] for j in xrange(p)]

for col in xrange(n):
	for row in xrange(p-1):
		if row == 0:
			for crow in xrange(H[row]):
				FM[row][col] += a[crow][col]
		else:
			for crow in xrange(H[row-1],H[row]):
				FM[row][col] += a[crow][col]
			# if row != 0 and row == p-2:
			# 	for crow in xrange(H[row],n):
			# 		FM[row+1][col] += a[crow][col]
		if row == p-2:
			for crow in xrange(H[row],n):
				FM[row+1][col] += a[crow][col]



lo, mid, hi = 0, 0, 10**18
while lo <= hi:
	if mid == (lo+hi)/2: break
	mid = (lo+hi)/2
	ans = fits2(mid, FM, V)
	if ans == 3:
		hi = mid-1
	elif ans == 2:
		hi = mid
	else:
		lo = mid+1

if lo > hi: lo, hi = hi, lo

if fits2(lo, FM, V):
	None
else:
	fits2(hi, FM, V)

TV = []
maxelem = max(max(FM[i]) for i in xrange(p))
avg = sum(FM[0])/p
for i in xrange(1,p):
	avg = max(sum(FM[i])/p, avg)
fits2(max(avg, maxelem), FM, TV)

for s in H:
	print s,
print

if len(V) == len(TV) == p-1:
	maxxx = 0
	for i in xrange(p):
		maxelem = max(FM[:TV[0]])
		for j in xrange(1,p-1):
			maxelem = max(maxelem, max(FM[TV[j-1]:TV[j]]))
		maxxx = max(maxxx, maxelem)
	maxx = 0
	for i in xrange(p):
		maxelem = max(FM[:V[0]])
		for j in xrange(1,p-1):
			maxelem = max(maxelem, max(FM[V[j-1]:V[j]]))
		maxx = max(maxx, maxelem)
	if maxxx < maxx:
		for s in TV:
			print s,
		print
	else:
		for s in V:
			print s,
		print
elif len(V) == p-1:
	for s in V:
		print s,
	print
elif len(TV) == p-1:
	for s in TV:
		print s,
	print
else:
	for s in H:
		print s,
	print