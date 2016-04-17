import sys
def solve(a, b, m,n):
	dp = [[0 for i in xrange(n+1)] for j in xrange(m+1)]
	for i in xrange(m+1):
		for j in xrange(n+1):
			if i == 0:
				dp[i][j] = j
			elif j == 0:
				dp[i][j] = i
			elif a[i-1] == b[j-1]:
				dp[i][j] = dp[i-1][j-1]
			else:
				dp[i][j] = 1 + min(dp[i][j-1],
					dp[i-1][j],
					dp[i-1][j-1])
	# for s in dp:
	# 	print s
	return dp[m][n]
inputs = sys.stdin.read()
inputl = inputs.split("\n")
t = int(inputl[0])
out = ""
for _ in xrange(1,2*t+1,2):
	a = inputl[_]
	b = inputl[_+1]
	out += str(solve(a,b, len(a), len(b)))+"\n"
sys.stdout.write(out)