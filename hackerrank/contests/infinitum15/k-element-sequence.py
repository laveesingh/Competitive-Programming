from math import factorial as f
MAX = 10**9+7
def solve(n, r):
	n -= r
	ans = 1
	if n < r-1:
		tod = 0
		cur = 2
		while n+r-1-tod > r-1:
			ans *= (n+r-1-tod)
			tod += 1
			while ans % cur == 0 and cur <= n:
				ans /= cur
				cur += 1
		return ans
	else:
		tod = 0
		cur = 2
		while n+r-1-tod > n:
			ans *= (n+r-1-tod)
			tod += 1
			while ans % cur == 0 and cur <= (r-1):
				ans /= cur
				cur += 1
		return ans

for _ in xrange(input()):
	n, k = map(int, raw_input().split())
	print solve(n, k)%MAX