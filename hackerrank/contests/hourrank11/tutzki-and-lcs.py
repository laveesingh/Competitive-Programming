from collections import defaultdict

def lcs(a, b):
	dp = [[0 for i in xrange(len(b)+1)] for j in xrange(len(a)+1)]
	for i in xrange(1,len(a)+1):
		for j in xrange(1,len(b)+1):
			if a[i-1] == b[j-1]:
				dp[i][j] = dp[i-1][j-1]+1
			else:
				dp[i][j] = max(dp[i][j-1], dp[i-1][j])
	return dp[len(a)][len(b)]

import string

a = raw_input()
b = raw_input()

stlcs = lcs(a, b)
ans = 0

for s in string.lowercase:
	for i in xrange(len(a)+1):
		ta = list(a)
		ta.insert(i, s)
		if(lcs(ta, b) == stlcs+1):
			ans += 1

print ans
