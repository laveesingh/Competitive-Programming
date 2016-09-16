'''input
7 7
3 1
2 1
7 6
6 3
5 3
4 3
7 2 3
7 1 1
2 3 5
3 6 2
4 2 4
5 3 10
6 1 20
3
5
6
7
'''

import os, sys, collections, itertools, fractions, math, random

ai = lambda : map(int, raw_input().split())
ii = lambda : int(raw_input())
inf = sys.maxint

n, m = ai()
G = [[] for i in xrange(n+1)]
parent = [0]*(n+1)
level = [0]*(n+1)
dist = [inf]*(n+1)

freq = [0]*(n+1)

for _ in xrange(n-1):
	x, y = ai()
	G[y].append(x)
	parent[x] = y;
	freq[y] += 1

# print freq
if max(freq) > 1:
	raise Exception("Too much collides")

ticket = [[] for i in xrange(n+1)]

for _ in xrange(m):
	v, k, w = ai()
	ticket[v].append((k,w))

Q = []
store = [0]
sqT = collections.defaultdict(int)
sq = 315
level[1] = 1
dist[1] = 0
for adj in G[1]:
	Q.append(adj)
	level[adj] = 2

def Find(i, j):
	ret = inf
	if j <= i: return inf
	if i%sq == 0 and j%sq == 0:
		k = i+sq
		while k <= j:
			ret = min(sqT[(i,k)], ret)
			i += sq
			k += sq
		return ret
	return min(store[i:j])

while Q:
	cur = Q.pop()
	flag = 0
	for child in G[cur]:
		flag = 1
		Q.append(child)
		level[child] = level[cur]+1

	for k, w in ticket[cur]:
		if k > len(store): k = len(store)
		if(k < 2*sq): 
			dist[cur] = min(dist[cur],min(store[-k:])+w)
			continue
		end = len(store)-1
		start = max(0,end-k+1)
		sst = start
		if start%sq != 0:
			sst = (start/sq + 1)*sq
		fst = start
		fen = sst
		sen = ((end+1)/sq)*sq
		tst = sen
		ten = end+1
		# print "cur:",cur,"store:",store,"start:",start,"end:",end,"=>",fst,fen,sst,sen,tst,ten
		dist[cur] = min(dist[cur], min(Find(fst, fen), Find(sst, sen), Find(tst, ten))+w)
			
	store.append(dist[cur])
	if len(store) > 0 and len(store)%sq == 0:
		# sqT.append(min(store[-sq:]))
		sqT[(len(store)-sq, len(store))] = min(store[-sq:])

	if Q and not flag:
		store = store[:level[parent[Q[-1]]]]

q = ii()
for i in xrange(q):
	h = ii()
	print dist[h]