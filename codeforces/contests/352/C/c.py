from math import ceil, floor

n = input()
a = map(float, raw_input().split())
x = 0
isum = 0
fsum = sum(a)
for i in xrange(2*n):
    if a[i] == int(a[i]):
        x += 1
    isum += floor(a[i])
ans = 10**10
for i in xrange(n-x, n+1):
    ans = min(ans, abs(fsum - isum - i))
print "%.3f" % ans
