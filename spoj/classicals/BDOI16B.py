inf = float("inf")

size=10**6 + 1
isprime = [1]*size
primes = [2]
isprime[0] = isprime[1] = 0
for i in xrange(4,size,2):
	isprime[i]=0
for i in xrange(3,int(size**0.5)+1,2):
	if isprime[i]:
		for j in xrange(i*i,size,2*i):
			isprime[j] = 0
for i in xrange(3,size,2):
	if isprime[i]: primes.append(i)

def solve(n,k):
	tk = k
	ans = 0
	while tk <= n:
		ans += n/tk
		tk *= k
	return ans
case = 0
for _ in xrange(int(raw_input())):
	
