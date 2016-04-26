INF = 10**10
# def solve(a, i, n):
# 	# print 'code'
# 	if n == i:
# 		return 0
# 	if a[i] == 0: return INF
# 	try:

# 		return min(1+solve(a,i+j,n) for j in xrange(1,min(a[i]+1, n+1-i)))
# 	except ValueError:
# 		return INF

def solve(a, n):
	dp = [0]*(n+1)
	for i in xrange(n,-1,-1):
		if i == n:
			dp[i] = 0
		elif a[i] == 0:
			dp[i] = INF
		else:
			dp[i] = min(1 + dp[i+j] for j in xrange(1,min(a[i]+1, n+1-i)))
	return dp[0]

a = map(int, raw_input().split())
n = len(a)-1
i = 0
print solve(a, n)