limit = 220000

isprime = [1]*limit

def sieve():
	global isprime
	isprime[0] = isprime[1] = 0
	for i in xrange(4, limit, 2):
		isprime[i] = 0
	for i in xrange(3, int(limit**0.5)+1, 2):
		if(isprime[i]):
			for j in xrange(i*i, limit, 2*i):
				isprime[j] = 0
	return

sieve()

fact = [1] * 41

def compute_factorial():
	global fact
	for i in xrange(1, 41):
		fact[i]  = fact[i-1]*i
	return

compute_factorial()

def solve(n):
	global isprime, fact

	dp = [0]*limit
	for i in xrange(2, limit):
		if isprime[i]:
			dp[i] = dp[i-1]+1
		else:
			dp[i]= dp[i-1]
	# print dp[:100]

	ans = 0
	for i in xrange(n/4 + 1):
		j = n - (4*i)
		ans += fact[i+j]/(fact[i]*fact[j])
	return dp[ans]

for _ in xrange(input()):
	print solve(input())