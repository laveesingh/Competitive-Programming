from math import factorial as f
import sys
mod = 10**9 + 7

# def comb(n, k):
# 	return f(n)/(f(n-k)*f(k))

# def power(a, b, mod):
# 	x = 1
# 	y = a
# 	while b > 0:
# 		if b%2:
# 			x = (x*y)%mod
# 		y = (y*y)%mod
# 		b /= 2
# 	return x

limit = 10**5

f  = [1]*(limit+1)

for i in xrange(2,limit+1):
	f[i] = (f[i-1]*i)%mod



def inv_euler(n, mod):
	return pow(n, mod-2, mod)

def comb(n, k, mod):
	global f
	return f[n]*((inv_euler(f[k],mod)*inv_euler(f[n-k], mod))%mod)%mod


def solve(a, n, k):
	c = a.count(0)
	if k == 1:
		return n-c+1
	if c == 0:
		if n == 1 or n == 2:
			return n
		if k%2:
			ans = 0
			for i in xrange(1,min(n,k)+1,2):
				ans += comb(n,i, mod)
				# print "ans:",ans,"i:",i
			return ans
		ans = 0
		for i in xrange(0, min(n,k)+1, 2):
			ans += comb(n, i, mod)
			# print "ans2:",ans
		return ans
	n = n - c
	# ans = 0
	# for i in xrange(min(n,k)+1):
	# 	ans += comb(n,i, mod)
	return pow(2,n,mod)

# t = int(raw_input())

# for _ in xrange(t):
# 	n, k = map(int, raw_input().split())
# 	a = map(int, raw_input().split())
# 	print solve(a, n,k)%mod


inputs = sys.stdin.read().split("\n")
t = int(inputs[0])
for i in xrange(1,2*t+1, 2):
	n, k = map(int, inputs[i].split())
	a = map(int, inputs[i+1].split())
	print solve(a,n,k)%mod

# def case():
# 	t = randint(1,10)
# 	print t
# 	for __ in xrange(t):
# 		i,j = randint(1,10), randint(1,10)
# 		print i,j
# 		for _ in xrange(i):
# 			print randint(-100,100),
# 		print


