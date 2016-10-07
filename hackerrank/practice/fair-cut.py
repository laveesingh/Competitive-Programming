ai = lambda : map(int,raw_input().split())

n, k = ai()
a = ai()
from itertools import combinations

def diff(a, b):
	ans = 0
	for s in a:
		for t in b:
			ans += abs(s-t)
	return ans
import sys
ans = sys.maxint
for comb in combinations(range(n), k):
	scomb = set(comb)
	a1 = []
	a2 = []
	for i in xrange(n):
		if i in scomb: a1.append(a[i])
		else: a2.append(a[i])
	ans = min(ans, diff(a1, a2))
print ans
