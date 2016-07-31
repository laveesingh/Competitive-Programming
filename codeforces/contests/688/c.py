from collections import defaultdict,deque
import sys
I = lambda : map(int, raw_input().split())
n,m = I()

graph = defaultdict(list)

for i in xrange(m):
	x, y = I()
	graph[x].append(y)
	graph[y].append(x)

f = set()
s = set()

visited = [0]*(n+1)

for edge in graph:
	if not visited[edge]:
		stack = deque()
		stack.append(edge)
		visited[edge] = 1
		while stack:
			cur = stack.pop()
			if cur in f:
				for adj in graph[cur]:
					if adj in f:
						print -1
						sys.exit(0)
					s.add(adj)
					if not visited[adj]: stack.append(adj)

			elif cur in s:
				for adj in graph[cur]:
					if adj in s:
						print -1
						sys.exit(0)
					f.add(adj)
					if not visited[adj]: stack.append(adj)
			else:
				for adj in graph[cur]:
					if adj in f:
						s.add(cur)
						break
					if adj in s:
						f.add(cur)
						break
				else:
					f.add(cur)

print len(f)
for x in f:
	print x,
print

print len(s)
for x in s:
	print x,
print

