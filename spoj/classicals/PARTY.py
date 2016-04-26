def solve(n, w, val, weight):
	dp = [[0 for i in xrange(w+1)] for j in xrange(n+1)]
	for i in xrange(n+1):
		for j in xrange(w+1):
			if i == 0 or j == 0:
				dp[i][j] = 0;
			elif weight[i-1] > j:
				dp[i][j] = dp[i-1][j]
			else:
				dp[i][j] = max(val[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j])
	i = w
	# for s in dp:
	# 	print s
	while dp[n][i-1] == dp[n][w]:
		i -= 1
	print i,dp[n][w]
import sys
inputs = sys.stdin.read()
inputs = inputs.split('\n')
i = 0
while 1:
	# w, n = map(int, raw_input().split())
	w, n = map(int, inputs[i].split())
	i += 1
	if w == 0 and n == 0: break
	val = []
	weight = []
	for _ in xrange(n):
		x, y = map(int, inputs[i].split())
		i += 1
		val.append(y)
		weight.append(x)
	solve(n, w, val, weight)
	# raw_input()
	i += 1
