from collections import defaultdict
import sys
sys.setrecursionlimit(100000)

class Edge:
	def __init__(self, n1, n2, w):
		self.node1 = n1
		self.node2 = n2
		self.weight = w

	def __repr__(self):
		string = "%d %d %d"%(self.node1,self.node2,self.weight)
		return string


n, m = map(int, raw_input().split())
graph = []
for _ in xrange(m):
	n1, n2, w  = map(int, raw_input().split())
	graph.append(Edge(n1, n2, w))

raw_input() # starting point, still of no use

def comp(e1, e2):
	if e1.weight == e2.weight:
		return -1 if e1.node1+e1.node2+e1.weight < e2.node1+e2.node2+e2.weight else 0
	return -1 if e1.weight < e2.weight else 0

graph.sort(comp)
# print "Sorted graph:",graph

d = defaultdict(int)
for i in xrange(1,n+1):
	d[i] = -1
def insame(a, b):
	global d
	print "a:",a,"b:",b

	cur = d[a]
	while cur != -1:
		cur = d[cur]
		if cur == b:
			return True
	cur = d[b]
	while cur != -1:
		cur = d[cur]
		if cur == a:
			return True
	return False

def find(i):
	global d
	if d[i] == -1:
		return i
	return find(d[i])

def union(x, y):
	global d
	xroot = find(x)
	yroot = find(y)
	d[xroot] = yroot


ans = 0
for edge in graph:
	# print "current edge:",edge
	if find(edge.node1) == find(edge.node2):
		None
	else:
		union(edge.node1, edge.node2)
		ans += edge.weight
	# print "weight",ans
	# print "d:",d
print ans