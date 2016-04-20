

# def solve(n, k):
# 	if k == 0 or k == 1: return k;
# 	if n == 1:
# 		return k
# 	return min(max(solve(n-1, x-1), solve(n, k-x)) for x in xrange(1,k+1)) + 1


def solve(n, k):
	dp = [[0 for i in xrange(k+1)] for j in xrange(n+1)]
	for i in xrange(n+1):
		for j in xrange(k+1):
			if j == 0 or j == 1 or i == 1:
				dp[i][j] = j
			else:
				dp[i][j] = min(max(dp[i-1][x-1], dp[i][j-x]) for x in xrange(1,j+1))+1
	return dp[n][k]


n = input()
k = input()
print solve(n, k)