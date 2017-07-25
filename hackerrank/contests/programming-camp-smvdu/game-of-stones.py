def solve(n):
    res = [False] * (n+1)
    for i in xrange(n+1):
        if i == 0 or i == 1:
            res[i] = False
        else:
            if i >= 2 and not res[i-2]:
                res[i] = True
            elif i >= 3 and not res[i-3]:
                res[i] = True
            elif i >= 5 and not res[i-5]:
                res[i] = True
            else:
                res[i] = False
    return "First" if res[n] else "Second"

for _ in xrange(input()):
    print solve(input())
