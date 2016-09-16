'''input
1
6 6
2 6
1 5
5 6
4 5
1 3
2 4
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())

degree = None
ispair = None
n = None
m = None
a = None

def comp(x, y):
	return degree[x] <= degree[y]

def contra(temp):
	for s in temp:
		for t in temp:
			if s != t and not ispair[s][t]:
				return 1
	return 0

def solve(first, second, vis):
	if len(vis) == len(a):
		return 1
	if not first and not second:
		first.append(a[0])
		vis.add(0)
		for i in xrange(1,len(a)):
			if (not ispair[a[0]][a[i]]):
				second.append(a[i])
				vis.add(i)
		if contra(second):
			return 0
	psize = len(vis)
	while len(vis) < len(a):
		for i in xrange(len(a)):
			f1, f2 = 1, 1
			if i not in vis:
				for s in first:
					if not ispair[s][a[i]]:
						f1 = 0
						break
				for s in second:
					if not ispair[s][a[i]]:
						f2 = 0
						break
				if not f1 and not f2:
					return 0
				elif not f1:
					second.append(a[i])
					vis.add(i)
				elif not f2:
					first.append(a[i])
					vis.add(i)
		if psize == len(vis):
			for i in xrange(len(a)):
				if i not in vis:
					# print "Hell yeah! I took the recursive calls"
					first.append(a[i])
					vis.add(i)
					fs = solve(first, second, vis)
					first.pop()
					second.append(a[i])
					ss = solve(first, second, vis)
					vis.remove(i)
					return (fs or ss)
		psize = len(vis)
	return 1



inputs = sys.stdin.read().split("\n");
ind = 0
t = int(inputs[ind])
ind += 1

for _ in xrange(t):
	n, m = map(int, inputs[ind].split())
	ind += 1
	ispair = [[0 for ii in xrange(n+1)] for jj in xrange(n+1)]
	degree = [0 for ii in xrange(n+1)]
	for __ in xrange(m):
		x, y = map(int, inputs[ind].split())
		ind += 1
		ispair[x][y] = 1
		ispair[y][x] = 1
		degree[x] += 1
		degree[y] += 1
	a = []
	for i in xrange(1,n+1):
		if degree[i] < n-1:
			a.append(i)
	if not a:
		ans = 1
	else:
		vis = set()
		a.sort(comp)
		fst = []
		sec = []
		ans = solve(fst, sec, vis)

	if ans: print "YES"
	else: print "NO"