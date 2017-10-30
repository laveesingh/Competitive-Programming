# import sys
# sys.setrecursionlimit(1000000)
# def solve(n, w, val): # assumption: val is sorted (if not sorted, it's not wrong)
# 	if n == 0 or w == 0: return 0
# 	if val[n-1] > w:
# 		return solve(n-1, w, val)
# 	return max(val[n-1]+solve(n, w-val[n-1], val), solve(n-1, w, val))

def solve(n, w, val):
	dp = [[0 for i in xrange(w+1)] for j in xrange(n+1)]
	for i in xrange(n+1):
		for j in xrange(w+1):
			if i == 0 or j == 0:
				dp[i][j] = 0
			elif val[i-1] > j:
				dp[i][j] = dp[i-1][j]
			else:
				dp[i][j] = max(val[i-1]+dp[i][j-val[i-1]], dp[i-1][j])
	return dp[n][w]
def main():
	n, w = map(int, raw_input().split())
	val = map(int, raw_input().split())
	print solve(n, w, val)

for _ in xrange(input()):
	main()