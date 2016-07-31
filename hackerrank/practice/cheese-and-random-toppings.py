from math import factorial as fact

def factorize(n):
	fct = []
	for i in xrange(2,50):
		if n == 0: break
		if(n%i == 0):
			fct.append(i)
			n /= i
	return fct

def mmi(a, mod):
	return pow(a, mod-2, mod)

def represent(n, mod):
	new = []
	while n > 0:
		new.append(n%mod)
		n /= mod
	return new

def smallC(n, r):
	if(r > n): return 0
	return fact(n)/(fact(n-r)*fact(r))

def bigC(n, r, mod):
	N = represent(n, mod)
	R = represent(r, mod)
	ans = 1
	for i in xrange(len(R)):
		ans = (ans * smallC(N[i], R[i]))%mod
	return ans

def solve(n, r, m):
	mods = factorize(m)
	rems = []
	for i in xrange(len(mods)):
		rems.append(bigC(n, r, mods[i]))
	ans = 0
	for i in xrange(len(mods)):
		ans += (rems[i] * (m/mods[i]) * mmi(m/mods[i], mods[i]))
	return ans%m

for _ in xrange(input()):
	print solve(*map(int, raw_input().split()))