import random
def isprime(n):
	if n < 2: return 0
	if n == 2: return True
	for i in xrange(10):
		x = random.randint(1,n-1)
		if pow(x, n-1, n) != 1:
			return 0
	return 1

def solve(n):
	if n == 3: return 2
	if n%2:
		n -= 2
	else: n -= 1
	while n > 0:
		if(isprime(n)): return n
		n -= 2
	return n

for _ in xrange(int(raw_input())):
	n = int(raw_input())
	print solve(n)