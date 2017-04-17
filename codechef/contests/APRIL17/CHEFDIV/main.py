N = 10**6 + 1
isprime = [1]*N
primes = []
prime_factors = {}
store = {}
remaining = {}

def total_divisors(n):
    if n == 1: return 0
    total_divs = 1
    if prime_factors.get(n) is None:
        return 1
    for pfact in prime_factors[n]:
        total_divs *= prime_factors[n][pfact] + 1
    return max(1, total_divs-1)  # This line may be the culprit

def sieve():
    isprime[0] = isprime[1] = 0
    for i in xrange(3, int(N**0.5 + 1.5), 2):
        if isprime[i]:
            for j in xrange(i*i, N, 2*i):
                isprime[j] = 0
    primes.append(2)
    for i in xrange(3, N, 2):
        if isprime[i]:
            primes.append(i)

def set_prime_factors(a, b):
    for prime in primes:
        #start = (a/prime) * prime  # Or this starting point can be the culprit
        #if start < a:
            #start += prime
        #if start == prime:
            #start += prime
        start = (a/prime) * prime + prime
        if a % prime == 0:
            start = a
        if start == prime:
            start += prime
        for i in xrange(start, b+1, prime):
            frequency = 0
            value = 1
            while(i%value == 0):
                frequency += 1
                value *= prime
            if prime_factors.get(i) is None:
                prime_factors[i] = {}
            value /= prime
            frequency -= 1
            remaining[i] /= value
            prime_factors[i][prime] = frequency 
    for i in xrange(a, b+1):
        if prime_factors.get(i):
            prime_factors[i][remaining[i]] = 1

def NBF(n):
    if prime_factors.get(n) is None:
        freq = {}
    else:
        freq = prime_factors[n]
    maxf, maxx = 0, 0
    for pfact in freq:
        if freq[pfact] > maxf:
            maxf = freq[pfact]
            maxx = pfact
    if freq.get(maxx):
        freq[maxx] -= 1
    ret = 1
    for pfact in freq:
        ret *= pow(pfact, freq[pfact])
    prime_factors[ret] = freq
    return ret

def solve(n):
    if n == 1: return 1
    if store.get(n):
        return store[n]
    ret = total_divisors(n) + 1
    ans = ret + solve(NBF(n))
    store[n] = ans
    return ans

sieve()
a, b = map(int, raw_input().split())
for i in xrange(a, b+1):
    remaining[i] = i
ans = 0
set_prime_factors(a, b)
for n in xrange(a, b+1):
    ans += solve(n) - 1
print ans
