from collections import defaultdict

limit = 10**6 + 2;
# print limit

isprime = [1]*limit

isprime[1] = isprime[0]= 0
for i in xrange(4, limit, 2):
	isprime[i] = 0
for i in xrange(3,int(limit**0.5)+1,2):
	if isprime[i]:
		for j in xrange(i*i, limit, 2*i):
			isprime[j] = 0
# print isprime[:100]
primes = []
for i in xrange(2, limit):
	if isprime[i]:
		primes.append(i)
# print primes[:100]
def factorize(n):
	global primes, isprime
	temp = []
	i = 0
	# print "factorizing for"
	while n > 1 and i < len(primes):
		# print "n",n
		if n%primes[i] == 0:
			while n%primes[i] == 0:
				temp.append(primes[i])
				n /= primes[i]
		i += 1
	if (n > 1):
		temp.append(n)
	return temp

t = int(raw_input())
for _ in xrange(t):
	n = int(raw_input())
	a = map(int, raw_input().split())
	freq = defaultdict(int)
	for s in a:
		facts = factorize(s)
		for t in facts:
			freq[t] += 1
	# print freq
	for t in freq:
		if freq[t] >= 2:
			print t
			break