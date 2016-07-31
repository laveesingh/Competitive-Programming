I = lambda : map(int,raw_input().split())

n, q, k  = I()
a = I()
for _ in xrange(q):
	x, y = I()
	a[x:y+1] = sorted(a[x:y+1])

print a[k]