MOD = 10**9 + 7
I = lambda : map(int, raw_input().split())
for _ in xrange(input()):
    p, q, r = I()
    X = I()
    Y = I()
    Z = I()
    ans = 0
    for x in X:
        for y in Y:
            for z in Z:
                if y >= x and y >= z:
                    ans = (ans + (x + y) * (y+z)) % MOD
    print ans
