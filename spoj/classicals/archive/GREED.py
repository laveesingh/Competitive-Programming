from collections import defaultdict
def solve(a, n):
	included = [0] * (n+1)
	rest = []
	for s in a:
		if not included[s]:
			included[s] = 1
		else:
			rest.append(s)
	remaining = []
	for i in xrange(1,n+1):
		if not included[i]:
			remaining.append(i)

	graph = defaultdict(int)
	num = input()
	for _ in xrange(num):
		x, y = map(int,raw_input().split())
		graph[x] = y
		graph[y] = x
	dist = defaultdict(
