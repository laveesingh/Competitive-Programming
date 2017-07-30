from itertools import combinations

def solve(a):
    if not a:
        return 0
    if len(a) == 1:
        return a[0]
    ret = -10 ** 9 
    Sum = sum(a)
    comb_list = []
    for length in xrange(1, len(a)+1):
        for comb in combinations(a, length):
            b = list(a)
            tcomb = list(comb)
            comb_list.append(tcomb)
            for s in tcomb:
                b.remove(s)
            ret = max(ret, sum(tcomb)*len(tcomb) + solve(b))
    return ret

for _ in xrange(input()):
    n = input()
    a = map(int, raw_input().split())
    print solve(a)
