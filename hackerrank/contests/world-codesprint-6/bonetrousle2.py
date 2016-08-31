'''input
5
12 8 3
10 3 3
9 10 2
9 10 2
18 8 5
'''

import os, sys, collections, itertools, fractions, math, random, heapq

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())


class Integer:
	def __init__(self, a):
		self.n = a
	def __le__(self, a):
		return self.n > a.n
	def __repr__(self):
		return "%d"%self.n



n = k = b = final = visited = cnt = None

def divide(n):
	# print "dividing: ",n
	if n < 3: return 0
	global visited, k
	x = n/2
	y = (n+1)/2
	if x == y:
		x -= 1
		y += 1
	# print "Initial:",x,y
	while visited[x] or visited[y]:
		x -= 1
		y += 1
		if x <= 0:
			return 0
	return (x,y)


def solve(store): # store is a set
	# print "store:",store, "cnt:",cnt
	global cnt, b, final, n, k
	if not store: return
	if cnt == b:
		final.extend([s.n for s in store])
		# print "ffinal:",final
		return
	cur = heapq.heappop(store)
	divd = divide(cur.n)
	if not divd:
		final.append(cur.n)
		# print "final:",final
		return solve(store)
	else:
		cnt += 1
		x,y = divd
		visited[cur.n] = 0
		heapq.heappush(store, Integer(x))
		visited[x] = 1
		heapq.heappush(store, Integer(y))
		visited[y] = 1
		solve(store)

for _ in xrange(ii()):
	n, k, b = ai()
	store = [Integer(n)]
	heapq.heapify(store)
	visited = collections.defaultdict(int)
	visited[n] = 1
	final = []
	cnt = 1
	solve(store)
	if cnt != b:
		print -1
	elif max(final) > k:
		print -1
	else:
		for s in final:
			print s,
		print