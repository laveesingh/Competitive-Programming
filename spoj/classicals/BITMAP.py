from collections import defaultdict, deque

def process(a, i, j, n, m): # assumption that i, j has not been visited yet
	visited = defaultdict(tuple) # tuple of isvisited and weight
	queue = deque()
	visited[(i,j)] = (1,0)
	queue.append((i,j))
	count = 0
	while 1:
		count += 1
		if count > 1000000:
			print "This is wrong"
			break
		ci, cj = queue.popleft()
		cw = visited[(ci, cj)][1]
		if ci >= n or cj >= m: continue
		# print "ci:",ci,"cj:",cj
		try:
			if ci < n and cj < m and a[ci][cj] == '1':
				return cw
		except IndexError: 
			print "Error:", ci,cj
		cons = [(ci+1, cj), (ci, cj+1), (ci-1, cj), (cj, cj-1)]
		bools = [ci == n-1, cj == m-1, ci == 0, cj == 0]
		for i in xrange(len(bools)):
			if not bools[i]:
				# print "ci:",ci,"cj:",cj,"appending:",cons[i]
				queue.append(cons[i])
				visited[cons[i]] = (1,cw+1)

t = int(raw_input())
for _ in xrange(t):
	n, m = map(int, raw_input().split())
	a = []
	b = [[0 for i in xrange(m)] for j in xrange(n)]
	for i in xrange(n):
		a.append(raw_input())
	for i in xrange(n):
		for j in xrange(m):
			b[i][j] = process(a, i, j, n, m)
	for s in b:
		for x in s:
			print x,
		print





