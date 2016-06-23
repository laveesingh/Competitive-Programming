
def solve(a, n, k):
	a = map(int,list(a))
	return max(reduce(int.__mul__, a[i:i+k]) for i in xrange(n-k+1))

for _ in xrange(input()):
	n, k = map(int, raw_input().split())
	a = raw_input()
	print solve(a, n, k)