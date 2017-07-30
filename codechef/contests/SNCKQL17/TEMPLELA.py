

def solve(n, a):
    if not n % 2:
        return False
    mid = (n + 1)/2
    first = a[:mid]
    second = a[mid:][::-1]
    return first == range(1, mid+1) and second == range(1, mid)


for _ in xrange(int(raw_input())):
    n = input()
    a = map(int, raw_input().split())
    print "yes" if solve(n, a) else "no"
