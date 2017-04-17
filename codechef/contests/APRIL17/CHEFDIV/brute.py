def smallest_prime_factors(N):
    N += 1
    sp = range(N)
    for i in xrange(2, N):
        if (sp[i] == i):
            for j in xrange(2*i, N, i):
                sp[j] = min(sp[j], i)
    return sp


def prime_factors(N):
    global sp  # Smallest prime factors array
    freq = dict()
    while N > 1:
        cur = sp[N]
        if freq.get(cur) is None:
            freq[cur] = 1
        else:
            freq[cur] += 1
        N /= cur
    return freq


def factors(N):
    freq = prime_factors(N)
    primes = []
    for prime in freq:
        primes.extend([prime]*freq[prime])
    divs = set() 
    for mask in xrange(1 << len(primes)):
        div = 1
        for j in xrange(len(primes)):
            if mask & (1<<j):
                div *= primes[j]
        divs.add(div)
    divs.remove(N)
    return sorted(divs)

def solve(N):
    divs = factors(N)
    ret = 1
    ret += len(divs)
    max_child = 0
    for div in divs:
        max_child = max(max_child, solve(div))
    return ret + max_child

a, b = map(int, raw_input().split())
ans = 0
sp = smallest_prime_factors(b)
for n in xrange(a, b+1):
    ans += solve(n) - 1
print ans
