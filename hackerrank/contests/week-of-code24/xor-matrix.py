

def find(a):
	global n, M
	parity = M / n
	if parity%2 == 0:
		rem = M%n
		dp = [0] * n
		for i in xrange(rem):
			dp[0] ^= a[i]
		for i in xrange(1,n):
			dp[i] = dp[i-1]^a[i-1]^a[(i+rem-1)%n]
		return dp
	else:
		rem = M%n
		xor = reduce(int.__xor__, a)
		dp = [xor] * n
		for i in xrange(rem):
			dp[0] ^= a[i]
		for i in xrange(1,n):
			dp[i] = dp[i-1] ^ a[i-1] ^ a[(i+rem-1)%n]
		return dp

ai = lambda : map(int, raw_input().split())
n, m = ai()
a = ai()

while m > 1:
	M = 1
	while M <= m:
		M <<= 1
	M >>= 1
	m = m - M + 1
	a = find(a)
	#print "A:",a
for s in a:
	print s,
print
