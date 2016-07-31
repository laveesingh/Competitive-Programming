import random

def isprime(n):
	if n < 2: return False
	if n == 2: return True
	for i in xrange(100):
		x = random.randint(1,n-1)
		if (pow(x, n-1, n) != 1):
			return False
	return True

for _ in xrange(input()):
	print "YES" if isprime(input()) else "NO"