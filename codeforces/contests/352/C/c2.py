from math import ceil, floor

a = None
store = None

def minimum(a, b):
    if abs(a) < abs(b):
        return a
    return b


def solve(i, x):
    if store[i][x] != -1:
        return store[i][x]
    if i == 2*n - 1:
        if x == n:
            return ceil(a[i]) - a[i]
        if x == n-1:
            return floor(a[i]) - a[i]
        else:
            return 10**10
    f = ceil(a[i]) - a[i]
    s = floor(a[i]) - a[i]
    if x == n:
        store[i+1][x] = solve(i+1, x)
        return store[i+1][x] + f
    if i-x == n:
        store[i+1][x+1] = solve(i+1, x+1)
        return store[i+1][x+1] + s
    store[i+1][x] = solve(i+1, x)
    store[i+1][x+1] = solve(i+1, x+1)
    return minimum(f + store[i+1][x], s + store[i+1][x+1])

n = input()
store = [[-1 for i in xrange(2*n)] for j in xrange(2*n)]
a = map(float, raw_input().split())
ans = solve(0, 0)
print "%0.3f" %abs(ans)
