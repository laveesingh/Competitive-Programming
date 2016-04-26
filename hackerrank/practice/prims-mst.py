import sys
from collections import defaultdict


def solve(graph, weight):
	d = {}
	for i in xrange(2,n+1):
		d[i] = sys.maxint
	d[1] = 0
	ans = 0
	mstset = set()
	while len(mstset) < n:
		mn = sys.maxint
		cur = 0
		# print d
		for s in d:
			if d[s] < mn:
				mn = d[s]
				cur = s
		# print "cur:",cur
		ans += d[cur]
		del d[cur]
		mstset.add(cur)
		# print "weight:",weight
		for node in graph[cur]:
			if d.get(node):
				try:
					d[node] = min(d[node],weight[(node,cur)])
				except:
					print "node:",node,"cur:",cur

	return ans

n, m = map(int, raw_input().split())
graph = defaultdict(list)
weight = defaultdict(int)
for i in xrange(m):
	x, y, w = map(int, raw_input().split())
	graph[x].append(y)
	graph[y].append(x)
	weight[(x,y)] = w
	weight[(y,x)] = w
raw_input()
print solve(graph, weight)