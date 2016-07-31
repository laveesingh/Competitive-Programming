from collections import defaultdict

INF = 10**10

I = lambda : map(int, raw_input().split())

def solve():
	n, m, p = I()
	a = []
	for i in xrange(n):
		a.append(I())
	indices = defaultdict(list)
	for i in xrange(n):
		for j in xrange(m):
			indices[a[i][j]].append((i,j))
	dist = [[0 for i in xrange(m)] for j in xrange(n)]
	for i in xrange(n):
		for j in xrange(m):
			if a[i][j] == 1:
				dist[i][j] = i+j
	for i in xrange(2,p+1):
		for x,y in indices[i]:
			dist[x][y] = INF
			for xi, yi in indices[i-1]:
				dist[x][y] = min(dist[x][y], dist[xi][yi]+abs(xi-x)+abs(yi-y))
	i = indices[p]
	print dist[i[0][0]][i[0][1]]

solve()