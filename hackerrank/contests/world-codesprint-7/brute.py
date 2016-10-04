n, m, k = map(int, raw_input().split())

from collections import defaultdict as dd

store  = dd(list)

a = [[0 for _ in xrange(m)] for __ in xrange(n)]

for _ in xrange(k):
	x, y, z = map(int, raw_input().split())
	x -= 1
	y -= 1
	z -= 1
	for i in xrange(y,z+1):
		a[x][i] = 1

cnt = 0
for s in a:
	for t in s:
		if t == 0:
			cnt += 1
print cnt
