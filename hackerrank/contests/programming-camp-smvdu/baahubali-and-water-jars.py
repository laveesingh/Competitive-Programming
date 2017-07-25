from fractions import gcd

def solve():
    a, b, c = map(int, raw_input().split())
    print "YES" if ((c <= a or c <= b) and c%gcd(a, b) == 0) else "NO"
        
for _ in xrange(input()):
    solve()
