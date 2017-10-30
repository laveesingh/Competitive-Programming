from collections import defaultdict
N = None
m = None
a = None
b = None
I = lambda : map(int, raw_input().split())

store = defaultdict(int)
def solve(i, n, m):
    if store[(i, n, m)]:
        return store[(i, n, m)]
    if i == 2*N - 1:
        return b[i % N]
    if n == 0:
        store[(i+1, n, m-1)] = solve(i+1, n, m-1)
        return b[i%N] + store[(i+1, n, m-1)]
    if m == n:
        store[(i+1, n-1, m)] = solve(i+1, n-1, m)
        return a[i%N] + store[(i+1, n-1, m)]
    store[(i+1, n-1, m)] = solve(i+1, n-1, m)
    store[(i+1, n, m-1)] = solve(i+1, n, m-1)
    store[(i, n, m)] = min(a[i%N] + store[(i+1, n-1, m)], b[i%N] + store[(i+1, n, m-1)])
    return store[(i, n, m)] 

N, m = I()
a = I()
b = I()
print (solve(1, N-1, N) + a[0]) * m/2
