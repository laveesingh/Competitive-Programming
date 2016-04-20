
I = lambda : map(int, raw_input().split())
N, W = map(int, raw_input().split())

val = []
weight = []
for i in xrange(N):
	x, y = I()
	val.append(x)
	weight.append(y)

# def solve(n, w):
# 	if n == 0 or w == 0: return 0
# 	if weight[n-1] > w:
# 		return solve(n-1, w)
# 	else:
# 		return max(val[n-1]+solve(n-1,w-weight[n-1]), solve(n-1,w))

def solve(n,w):
	# dp  = [[0 for i in xrange(w+1)] for j in xrange(n+1)]
	dp = [[0 for i in xrange(w+1)] for j in xrange(2)]
	for i in xrange(n+1):
		for j in xrange(w+1):
			if i%2 == 0:
				if i == 0 or j == 0: dp[0][j] = 0
				elif weight[i-1] > j:
					dp[0][j] = dp[1][j]
				else:
					dp[0][j] = max(val[i-1]+dp[1][j-weight[i-1]], dp[1][j])
			else:
				if i == 0 or j == 0: dp[1][j] = 0
				elif weight[i-1] > j:
					dp[1][j] = dp[0][j]
				else:
					dp[1][j] = max(val[i-1]+dp[0][j-weight[i-1]],dp[0][j])


	return dp[n%2][w] if dp[n%2][w-1]!=dp[n%2][w] else "Got caught!"


print solve(N,W)