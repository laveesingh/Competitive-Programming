

def solve(a, n):
	dp = [0]*(n+1)
	for i in xrange(n+1):
		if i == 0: dp[i] = 0
		else:
			dp[i] = max(a[j]+dp[i-j-1] for j in xrange(i))
	return dp[n];

n = input()
a = map(int, raw_input().split())
print solve(a, n)