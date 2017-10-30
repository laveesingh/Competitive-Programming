from itertools import permutations

def good(a):
    n = len(a)
    mediansum = 0.0
    mediancount = 0.0
    for i in xrange(n):
        for j in xrange(i, n):
            if (j - i) % 2 == 0:
                ind = (i + j)/2
                mediansum += float(a[ind])
                mediancount += 1.0
            else:
                ind = (i + j)/2
                mediansum += (a[ind] + a[ind+1])/2.0
                mediancount += 1.0
    mean = mediansum / mediancount
    return n-1 <= mean <= n+1

def brute(n):
    for i in xrange(1, 100):
        arr = range(i, n+i)
        if good(arr):
            return arr
    return -1

for _ in xrange(input()):
    n = input()
    ans = brute(n)
    if not ans:
        print -1
    else:
        for s in ans: print s,
        print
