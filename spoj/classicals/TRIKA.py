def I():
	a = raw_input()
	while not a:
		a = raw_input()
	a = a.split()
	# b = [[int(s) for s in t.split("\xc3\x82")] for t in a]
	b =[]
	for s in a:
		for t in s.split("\xc3\x82"):
			if t:
				b.append(int(t))
	return b

n, m = I()
x, y = I()
a = []
for i in xrange(n):
	a.append(I())
x -= 1
y -= 1

dp = [[0 for i in xrange(m)] for j in xrange(n)]

for i in xrange(y+1, m):
	dp[x][i] = dp[x][i-1]+a[x][i]

for i in xrange(x+1, n):
	dp[i][y] = dp[i-1][y]+a[i][y]

for i in xrange(x+1, n):
	for j in xrange(y+1, m):
		dp[i][j] = min(dp[i-1][j],dp[i][j-1])+a[i][j]

ans = dp[n-1][m-1]
# for i in xrange(y, m):
# 	if(dp[n-1][i] < ans): ans = dp[n-1][i]

if(ans > a[x][y]):
	print "N"
else:
	print "Y",a[x][y]-ans
