
def solve(n, k):
	if n == k: return 1
	x = float(k-1)
	y = float(n-1)
	ans = 1.0
	while y >= n-k+1 or x >= 1:
		if (y >= n-k+1):
			ans *= y
			y -= 1
		if x >= 1:
			ans /= x
			x -= 1
	return int(ans)


for _ in xrange(int(raw_input())):
	n, k = map(int, raw_input().split())
	print solve(n, k)
