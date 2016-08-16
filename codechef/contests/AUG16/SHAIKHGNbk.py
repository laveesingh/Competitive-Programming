'''input
7
1 0 1 0 0 0 0
0 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 1
0 0 0 0 1 0 1
7
5 1
78 5
42 5
46 1
91 6
48 4
16 6
'''

from collections import defaultdict
import sys

graph = None

def solve(k, x):
	hm = [0]*n
	hm[x] = 1
	for i in xrange(1,k+1):
		nhm = [0]*n
		for i,s in enumerate(hm):
			if s == 1:
				for adj in graph[i]:
					nhm[adj] = 1
		hm = list(nhm)
	ans = []
	for i,s in enumerate(hm):
		if s == 1:
			ans.append(i)
	return ans


# Main programs starts here

graph = defaultdict(list)

n = int(raw_input())
for i in xrange(n):
	temp = raw_input().split()
	for j in xrange(n):
		if temp[j] == '1':
			graph[i].append(j)

m = int(raw_input())
for _ in xrange(m):
	k, x = map(int, raw_input().split())
	x -= 1
	ans = solve(k,x)
	print len(ans)
	if len(ans) == 0:
		print -1
	else:
		for s in ans:
			print s+1,
		print 