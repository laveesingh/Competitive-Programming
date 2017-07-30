from collections import defaultdict
class Edge:
	def __init__(self, a, b, c):
		self.n1 = a
		self.n2 = b
		self.w = c
	def __repr__(self):
		string = "%d %d %d"%(self.n1,self.n2,self.w)
		return string

def comp(e1, e2):
	if (e1.w == e2.w):
		return -1 if e1.w+e1.n1+e1.n2 < e2.w+e2.n1+e2.n2 else 0
	return -1 if e1.w < e2.w else 0

d = None # disjoint set data structure

def find(i):
	global d
	return i if d[i]==-1 else find(d[i])

def Union(x, y):
	global d
	d[find(x)] = find(y)


for _ in xrange(int(raw_input())):
	raw_input()
	n = int(raw_input())
	graph = []
	istaken = defaultdict(int)
	# d = defaultdict(int)
	# for i in xrange(1,n+1):
	# 	d[i] = -1
	d=[-1 for s in xrange(n+1)]
	for i in xrange(1,n+1):
		raw_input()
		nei=int(raw_input())
		for j in xrange(nei):
			x = i
			if (istaken[(x,y)]):
				continue
			y, z = map(int, raw_input().split())
			istaken[(x,y)] = istaken[(y,x)] = 1
			graph.append(Edge(x, y, z))
	graph.sort(comp)
	# for edge in graph:
	# 	print edge
	ans = 0
	for edge in graph:
		if find(edge.n1) == find(edge.n2):
			continue
		ans += edge.w
		Union(edge.n1, edge.n2)
	print ans

