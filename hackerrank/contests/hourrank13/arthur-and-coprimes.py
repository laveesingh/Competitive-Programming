from math import log
n = input()

a = [0]*(n+1)

isprime = [1]*(n+1)
isprime[0] = 0
isprime[1] = 0

for i in xrange(4,n+1, 2):
    isprime[i] = 0
for i in xrange(3, int(n**0.5)+2, 2):
    if isprime[i]:
        for j in xrange(i*i, n+1, 2*i):
            isprime[j] = 0

primes = []

for i in xrange(n+1):
    if isprime[i]:
        primes.append(i)

ans = 0
for prime in primes:
    st = prime
    while st <= n:
        if st >= 6:
            if log(st, prime)-int(log(st,prime)) != 0:
                if not a[st]: 
                    print prime, st
                    ans += 1
                a[st] = 1
        st += prime

print ans
