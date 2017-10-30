
def solve(a):
    n = len(a)
    mindiff = 10**9
    for i in xrange(n):
        b = list(a)
        del b[i]
        for j in xrange(n-1):
            c = list(b)
            del c[j]
            c.sort()
            diff = 0
            for k in xrange(1, n-2, 2):
                diff += c[k] - c[k-1]
            mindiff = min(diff, mindiff)
    return mindiff

n = input()
a = map(int, raw_input().split())
print solve(a)
