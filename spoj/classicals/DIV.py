limit = 10**6 + 1

isprime = [1]*limit

isprime[0] = isprime[1] = 0
for i in xrange(4,limit,2):
	isprime[i] = 0
for i in xrange(3,int(limit**0.5)+1,2):
	if(isprime[i]):
		for j in xrange(i*i, limit, 2*i):
			isprime[j] = 0

primes = [2]

for i in xrange(3, limit, 2):
	if(isprime[i]):
		primes.append(i)

ans = []
for i in xrange(len(primes)-1):
	s = primes[i]
	for j in xrange(i+1, len(primes)):
		t = primes[j]
		if t == s:
			continue
		if s*pow(t,2) > limit and t*pow(s,2) > limit:
			break
		for u in primes:
			tx = pow(s,u-1)
			if tx > limit:
				break
			for v in primes:
				if u == v: continue
				ty = pow(t,v-1)
				if ty>limit or tx*ty > limit:
					break
				else:
					if(tx*ty == 999952): print s, t, u, v
					ans.append(tx*ty)

powers = [6, 10, 14, 15, 21]
bases = [2, 3, 5, 7]
for base in bases:
	for power in powers:
		if pow(base, power-1) < limit:
			ans.append(pow(base, power-1))

ans.sort()
tocheck = [50, 99, 162, 999524, 999728, 999927]
for s in tocheck:
	print ans.index(s), (ans.index(s)+1)%9