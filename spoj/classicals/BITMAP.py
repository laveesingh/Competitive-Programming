
from collections import defaultdict, deque
import sys

matrix = None

def bfs(i, j, a):
	global matrix
	n = len(a)
	m = len(a[0])
	# print "BFS for ",i,j
	indq = deque()
	indq.append((i,j,0))
	visited = defaultdict(int)
	visited[(i,j)] = 1
	while indq:
		cur = indq.popleft()
		x, y,c = cur[0],cur[1],cur[2]
		matrix[x][y] = min(matrix[x][y], c)
		indlist = [(x+1,y,c+1),(x-1,y,c+1),(x,y+1,c+1),(x,y-1,c+1)]
		for index in indlist:
			if not visited[(index[0],index[1])] and index[0] >= 0 and index[0] < n and index[1] >= 0 and index[1] < m and a[index[0]][index[1]]!='1':
				# print "appending...",index
				indq.append(index)
				visited[(index[0],index[1])] = 1

def solve(a, n, m):
	n = len(a)
	m = len(a[0])
	indo = []
	global matrix
	matrix = [[1024 for j in xrange(len(a[0]))] for i in xrange(len(a))]
	for i in xrange(len(a)):
		for j in xrange(len(a[i])):
			# try:
				if a[i][j] == '1':
					indo.append((i,j))
			# except:
			# 	print "error for",i,j
	for i, j in indo:
		bfs(i,j,a)

I = lambda : map(int, raw_input().split())

def main():
	n, m = I()
	a = []
	for i in xrange(n):
		a.append(raw_input())
	solve(a,n,m)
	# print matrix
	for s in matrix:
		for t in s:
			print t,
		print

for _ in xrange(input()):
	main()
