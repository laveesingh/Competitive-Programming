
def solve(n, k):
	dp = [[0 for i in xrange(k+1)] for j in xrange(n+1)]
	for i in xrange(n+1):
		for j in xrange(k+1):
			if j == 0 or j == 1 or i == 1:
				dp[i][j] = j
			else:
				dp[i][j] = min(max(dp[i-1][x-1], dp[i][j-x]) for x in xrange(1,j+1))+1
	return dp[n][k]
	