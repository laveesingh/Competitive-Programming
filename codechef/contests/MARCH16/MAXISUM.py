
def interaction(a, b):
	return sum([x*y for x,y in zip(a,b)])

def solve(a, b, k):
	mn = b[0]
	mp = b[0]
	for s in b:
		if s < mn:
			mn = s
		if s > mp:
			mp = s
	i = mn if abs(mn) > abs(mp) else mp
	i = b.index(i)
	if b[i] < 0:
		a[i] -= k
	else: a[i] += k
	return interaction(a, b)

I = lambda : map(int, raw_input().split())

for _ in xrange(input()):
	n, k = I()
	a = I()
	b = I()
	print solve(a, b, k)