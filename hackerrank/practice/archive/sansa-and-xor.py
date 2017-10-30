def solve(n, a):
	if n%2 == 0:
		return 0
	return reduce(int.__xor__, a[0::2])

for _ in xrange(input()):
	print solve(input(), map(int, raw_input().split()))