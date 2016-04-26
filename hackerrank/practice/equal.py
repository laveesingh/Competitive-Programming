
def solve(a, n):
	m = min(a)
	r = 10**10
	for t in xrange(m-4, m+1):
		s = 0
		for i in xrange(n):
			d = a[i] - t
			s += d/5
			d %= 5
			s += d/2
			d %= 2
			s += d
		r = min(r, s)
	return r

for _ in xrange(input()):
	n = input()
	print solve(map(int, raw_input().split()), n)		