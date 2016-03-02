MAX = 10**5

# First count all the primes upto square-root of the upper bound

mx = int(MAX ** 0.5) + 1

primes = [1]*mx

primes[0] = 0
primes[1] = 0

for i in xrange(4, mx, 2):
	primes[i] = 0

for i in xrange(3, int(mx ** 0.5 + 1), 2):
	for j in xrange(i*i, mx, i):
		primes[j] = 0

for i, s in enumerate(primes):
	if s:
		print i,