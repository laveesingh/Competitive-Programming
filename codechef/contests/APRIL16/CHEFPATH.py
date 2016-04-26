def solve(n, m):
	if n == 1:
		return m == 2
	if m == 1:
		return n == 2
	return not m%2 or not n%2

for _ in xrange(input()):
	print "Yes" if solve(*map(int, raw_input().split())) else "No"