from collections import defaultdict, deque
import sys

INF = 10000000000

graph = defaultdict(list)
weights = defaultdict(int)

def weight(a, b):
	global weights
	if weights.get((a,b)):
		return weights[(a,b)]
	return weights[(b,a)]

def solve(a, b):
	global graph
	queue = deque()
	queue.append(a)
	pen = {x:INF for x in graph}
	pen[a] = 0
	visited = defaultdict(int)

	while len(queue) > 0:
		# print "pen:",pen
		cur = queue.popleft()
		visited[cur] = 1
		# print "cur:",cur,
		for node in graph[cur]:
			if not visited[node]:
				# print "node:",node,
				pen[node] = min(pen[node], pen[cur]|weight(node, cur))
				
				queue.append(node)
		# print

	print pen
	if pen[b] == INF: return -1
	return pen[b]


I = lambda : map(int, raw_input().split())
n, m = I()
for _ in xrange(m):
	x, y, z = I()
	graph[x].append(y)
	graph[y].append(x)
	if (not weights[(x,y)] and not weights[(y,x)]) or (weights[(x,y)] > z or weights[(y,x)] > z):
		weights[(x,y)] = z

print solve(*I())