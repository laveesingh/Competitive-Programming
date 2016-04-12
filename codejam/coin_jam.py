# MAX = 9 * 10**6
# primes = [1]*MAX
# limit = 2**16 + 1
# primes[0] = primes[1] = 0
# for i in xrange(4,MAX,2):
# 	primes[i] = 0

# for i in xrange(3,int(MAX**0.5+1.5),2):
# 	if primes[i]:
# 		for j in xrange(i*i,MAX,i):
# 			primes[j] = 0

# def factor(a):
# 	if not a%2: return 2
# 	else:
# 		for i in xrange(3,int(a**0.5+1.5),2):
# 			if not a%i:
# 				return i
# 	return 1

from collections import defaultdict

divisors = defaultdict(int)


def is_prime(a):
	global divisors
	if not a%2: 
		divisors[a] = 2
		return False
	for i in xrange(3,int(a**0.5+1.5),2):
		if not a%i:
			divisors[a] = i
			return False
	return True


# def not_prime(a):
# 	for i in xrange(2,10):
# 		temp = int(a,i)
# 		try:
# 			if is_prime(temp):
# 				return False
# 		except IndexError:
# 			print "temp:",temp
# 			return False
# 	return True

def not_prime(a):
	for i in xrange(2,11):
		temp = int(a,i)
		if is_prime(temp):
			return False
	return True

def solve(index,n, j):
	ans = []
	for num in xrange(2**(n-1)+1,2**n,2):
		a = bin(num)[2:]
		if not_prime(a):
			ans.append(a)
		if len(ans) == j:
			break
	print "Case #%d:"%(index+1)
	for s in ans:
		print s,
		for i in xrange(2,11):
			num = int(s,i)
			print divisors[num],

		print


inputs = []
for _ in xrange(input()):
	inputs.append(map(int, raw_input().split()))

for i,s in enumerate(inputs):
	solve(i,s[0],s[1])
	