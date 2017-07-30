

def solve(a, b):
    fx1, fy1, fx2, fy2 = a
    sx1, sy1, sx2, sy2 = b
    p1 = (fx1, fy1)
    p2 = (fx2, fy2)
    p3 = (sx1, sy1)
    p4 = (sx2, sy2)
    if p1 == p3 or p1 == p4 or p2 == p3 or p2 == p4:
        return True
    if fx1 == fx2 == sx1 == sx2:
        if fy1 > fy2:
            fy1, fy2 = fy2, fy1
        if sy1 > sy2:
            sy1, sy2 = sy2, sy1
        if fy1 <= sy1:
            return sy1 <= fy2
        else:
            return fy1 <= sy2
    elif fy1 == fy2 == sy1 == sy2:
        if fx1 > fx2:
            fx1, fx2 = fx2, fx1
        if sx1 > sx2:
            sx1, sx2 = sx2, sx1
        if fx1 <= sx1:
            return sx1 <= fx2
        else:
            return fx1 <= sx2
    return False


for _ in xrange(input()):
    a = map(int, raw_input().split())
    b = map(int, raw_input().split())
    print "yes" if solve(a, b) else "no"
