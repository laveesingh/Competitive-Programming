from collections import defaultdict
# def solve(a):
# 	n = len(a)
# 	dp = [[0 for i in xrange(n)] for j in xrange(n)]
# 	for i in xrange(n):
# 		for j in xrange(n):
# 			if i == j:
# 				dp[i][j] = 1
# 			elif a[i] == a[j]:
# 				dp[i][j] = dp[i+1][j-1]+2
# 			else:
# 				dp[i][j] = max(dp[i+1][j], dp[i][j-1])
# 	for s in dp:
# 		print s
# 	return dp[n-1][n-1]

store  = defaultdict(int)
def solve(a, i, j):
	global store
	if store[(i,j)]: return store[(i,j)]
	if i == j:
		store[(i,j)] = 1
	elif a[i] == a[j] and i +1 == j:
		store[(i,j)] = 2
	elif a[i] == a[j]:
		store[(i,j)] = solve(a, i+1, j-1)+2
	else:
		store[(i,j)] = max(solve(a, i, j-1), solve(a, i+1, j))
	return store[(i,j)]

n=input()

print solve(raw_input(),0,n)
