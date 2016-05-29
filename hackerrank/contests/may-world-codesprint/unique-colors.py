
from collections import defaultdict

I = lambda : map(int, raw_input().split())

tree = defaultdict(list)

store = defaultdict(set)

n = input()
colors = I()

for _ in xrange(n-1):
	x, y = I()
	tree[x].append(x)
	tree[x].append(y)
	tree[y].append(x)
	tree[y].append(y)

for node in tree:
	for adj in tree[node]:
		store[(node, adj)].add(colors[node-1])
		store[(node, adj)].add(colors[adj-1])

for i in xrange(1,n+1):
	for j in xrange(1,n+1):
		if not store[(i,j)]:
			k = 1
			while k <= n:
				if store[(i,k)] and store[(k,j)]:
					store[(i,j)] = store[(i,k)].union(store[(k,j)])if not store[(i,j)] else min(store[(i,j)], store[(i,k)].union(store[(k,j)]))
				k += 1

for i in xrange(1,n+1):
	ans =0
	for j in xrange(1,n+1):
		print "i,j: ", i,j, "set: ", store[(i,j)]
		ans += len(store[(i,j)])
	print ans
