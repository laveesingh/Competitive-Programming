
def minCost(a, m, n):
	dp = [[0 for i in xrange(n)] for j in xrange(m)]
	dp[0][0] = a[0][0]
	for i in xrange(1,m):
		dp[i][0] = a[i][0] + dp[i-1][0]
	for j in xrange(1,n):
		dp[0][j] = a[0][j] + dp[0][j-1]
	for i in xrange(1,m):
		for j in xrange(1,n):
			dp[i][j] = a[i][j] + min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
	return dp[m-1][n-1]

a = [[1,2,3],
	[4,8,2],
	[1,5,3]]

print minCost(a,3,3)
