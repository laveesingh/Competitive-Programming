from fractions import gcd

for _ in xrange(input()):
    n = input()
    a = map(int, raw_input().split())
    print "YES" if reduce(gcd, a) == 1 else "NO"
