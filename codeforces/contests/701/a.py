n = input()
a = map(int, raw_input().split())

total = sum(a)/n
total *= 2
visited = [0]*(n+1)

pairs = []

# for i in xrange(n-1):
# 	if not visited[i]:
# 		for j in xrange(i+1,n):
# 			if a[i]+a[j] == total and not visited[j]:
# 				pairs.append((i,j))
# 				visited[i] = 1
# 				visited[j] = 1
# 				break

# for i,j in pairs:
# 	print i+1, j+1

from collections import defaultdict

b = defaultdict(int)
for i in xrange(len(a)):
	b[i+1] = a[i]

for i in xrange(1,n+1):
	t = 0
	if not visited[i]:
		for s in b:
			if s != i and b[s]+b[i] == total:
				t = s
	if not visited[i]:
		del b[i]
		del b[t]