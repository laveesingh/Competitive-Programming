from collections import defaultdict
store = defaultdict(int)
def exchange(n):
    if n == 0 or n == 1: return n
    if store[n]: return store[n]
    a = exchange(n/2)
    store[n/2] = a
    b = exchange(n/3)
    store[n/3] = b
    c = exchange(n/4)
    store[n/4] = c
    store[n] = max(n, a+b+c)
    return store[n]

while True:
    try:
        n = int(raw_input())
        print exchange(n)
    except:
        break
