M = 10**6 + 1
primes = [1] * M
primes[0] = 0
primes[1] = 0

for i in xrange(4, M, 2):
	primes[i] = 0
for i in xrange(3, int(sqrt(M)+1), 2):
	if (primes[i]):
		for j in xrange(i*i, M, i):
			primes[i] = 0

