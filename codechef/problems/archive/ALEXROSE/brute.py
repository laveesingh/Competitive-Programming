import collections
import itertools

a = None
I = lambda: map(int, raw_input().split())


def cuts(comb):
    counter = collections.Counter(comb)
    pivot = min(counter.keys())
    return sum(counter.values()) - counter[pivot]


def solve(n, k):
    ans = 10 ** 9
    for comb in itertools.permutations(a):
        mincut = 0
        for ind in xrange(0, n, k):
            mincut += cuts(comb[ind:ind+k])
        ans = min(mincut, ans)
    return ans

for _ in xrange(input()):
    n, k = I()
    a = I()
    print solve(n, k)
