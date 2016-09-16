'''input
1
6 10
863 1528 1337 1131 780 1497
0 1 5
0 6 6
1 5 5
0 2 6
0 1 4
1 1 3
1 2 6
0 5 6
1 3 5
1 1 4
'''
import os, sys, collections, itertools, fractions, math, random
ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())
limit = 10**5
L = A = n = m = T = None
lpdiv = [0]*(limit*10)

def sieve():
	M = 10*limit
	for i in xrange(M):
		lpdiv[i] = i if i%2 else 2
	lpdiv[0] = 0
	for i in xrange(3,int(M**0.5)+1,2):
		if lpdiv[i] == i:
			for j in xrange(i*i, M, 2*i):
				lpdiv[j] = min(lpdiv[j], i)

def combine(a, b, c):
	print "a:",a
	print "b:",b
	del c[:]
	n = len(a)
	m = len(b)
	if n > m:
		sz = n-m
		c.extend(a[:sz])
		for i in xrange(m):
			c.append(max(a[sz+i], b[i]))
	elif m > n:
		sz = m-n
		c.extend(b[:sz])
		for i in xrange(n):
			c.append(max(a[i], b[sz+i]))
	else:
		for i in xrange(n):
			c.append(max(a[i], b[i]))
	print "c:",c

def refresh(node):
	while T[node] and L[node] > 0:
		T[node].pop()
		L[node] -= 1
		if 2*node < 4*n+5:
			L[2*node] += 1
			L[2*node+1] += 1

def pdiv(n, a):
	del a[:]
	ret = list()
	while n > 1:
		ret.append(lpdiv[n])
		n /= lpdiv[n]
	a.extend(ret[::-1])

def build(node, i, j):
	if i == j:
		# print >> sys.stderr, "For node:",node
		pdiv(A[i], T[node])
		# print >> sys.stderr, "\tCombined:",T[node]
	else:
		mid = (i+j)/2
		build(2*node, i, mid)
		build(2*node+1,mid+1,j)
		# print >> sys.stderr, "For Node:",node
		# print >> sys.stderr, "\tleft half:",T[2*node]
		# print >> sys.stderr, "\tright half:",T[2*node+1]
		combine(T[2*node], T[2*node+1], T[node])
		# print >> sys.stderr, "\tCombined:",T[node]

def update(node, st, en, i, j):
	refresh(node);
	if not T[node]: return
	if st == i and en == j:
		T[node].pop()
		if 2*node < 4*n+5:
			L[2*node] += 1
			L[2*node+1] += 1
	else:
		mid = (st+en)/2
		if j <= mid: update(2*node, st, mid, i, j)
		elif i > mid: update(2*node+1, mid+1, en, i,j)
		else:
			update(2*node, st, mid, i, mid)
			update(2*node, mid+1, en, mid+1, j)
		refresh(2*node)
		refresh(2*node+1)
		combine(T[2*node],T[2*node+1],T[node])


def get(node, st, en, i, j):
	refresh(node)
	if not T[node]: return 1
	if st == i and en == j: return T[node][-1]
	else:
		mid = (st+en)/2
		if j <= mid: return get(2*node, st, mid, i, j)
		elif i > mid: return get(2*node+1, mid+1, en, i, j)
		else:
			f = get(2*node, st, mid, i, mid)
			s = get(2*node+1, mid+1, en, mid+1,j)
			return max(f,s)

sieve()

for _ in xrange(ii()):
	n, m = ai()
	A = ai()
	L = [0]*(4*n+5)
	T = [[] for x in xrange(4*n+5)]
	build(1,0,n-1)
	print T
	for i in xrange(m):
		type, x, y = ai()
		x, y = x-1, y-1
		if type:
			print get(1,0,n-1,x,y),
		else:
			update(1,0,n-1,x,y)
			print T
	print
