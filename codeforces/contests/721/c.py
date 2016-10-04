
ai = lambda : map(int, raw_input().split())

n, m, T = ai()

from collections import defaultdict as dd
from collections import deque
store = dd(list)
dist = [[0 for i in xrange(n+1)] for j in xrange(n+1)]

for i in xrange(m):
	x, y, z = ai()
	store[x].append(y)
	dist[x][y] = z
	dist[y][x] = z

q = deque()

q.append([1, 0, [1]])

# vis  = [0] * (n+1)

# vis[1] = 1
path = []

while q:
	cur = q.popleft()
	for child in store[cur[0]]:
		if cur[1]+dist[cur[0]][child] <= T:
			temp = [child, cur[1]+dist[cur[0]][child], cur[2][:]]
			temp[2].append(child)
			# if not vis[child]:
			q.append(temp)
			# print child, temp
			if child == n and len(temp[2]) > len(path):
				path = temp[2]
			# vis[child] = 1

print len(path)
for s in path:
	print s,