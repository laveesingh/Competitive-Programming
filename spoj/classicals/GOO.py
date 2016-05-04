
def solve(n):
	x = 2 ** (n-1)
	print x, x+(x*(n-1))/2

for _ in xrange(int(raw_input())):
	solve(int(raw_input()))