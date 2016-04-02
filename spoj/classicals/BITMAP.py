from collections import defaultdict
import sys
sys.setrecursionlimit(1000000)
a = None
store = defaultdict(int)

def bfs(i, j):
	if a[i][j] == '1':
		return 0
	if i == 0 and j == 0:
		return 1+min(bfs(i,j+1),bfs(i+1,j))
	if i == 0 and j == n-1:
		return 1+min(bfs(i,j-1),bfs(i+1,j))
	if i == 0:
		return 1+min(bfs(i,j-1),bfs(i+1,j),bfs(i,j+1))
	if j == 0 and i == m-1:
		return 1+min(bfs(i,j+1),bfs(i-1,j))
	if j == 0:
		return 1+min(bfs(i-1,j),bfs(i,j+1),bfs(i+1,j))
	if i == m-1 and j == n-1:
		return 1+min(bfs(i-1,j),bfs(i,j-1))
	if i == m-1:
		return 1+min(bfs(i-1,j),bfs(i,j-1),bfs(i,j+1))
	if j == n-1:
		return 1+min(bfs(i-1,j),bfs(i+1,j),bfs(i,j-1))
	return 1+min(bfs(i,j+1),bfs(i,j-1),bfs(i-1,j),bfs(i+1,j))

a=[]
m, n = map(int, raw_input().split())
for i in xrange(m):
	a.append(raw_input())
print bfs(0,0)
