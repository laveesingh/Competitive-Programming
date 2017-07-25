m = 10**9 + 7

def solve(a, b, c, m):
    x = pow(b, c, m-1)
    return pow(a, x, m)

a, b, c = map(int, raw_input().split())
print solve(a, b, c, m)
