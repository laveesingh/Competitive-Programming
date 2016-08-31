'''input
5 5
2 4 9 2 5
'''

I = lambda : map(int, raw_input().split())

n, k = I()

a = I()

from collections import defaultdict
import sys
inf =sys.maxint

d = defaultdict(int)

for i in xrange(n):
	x = i+1 if i < n/2 else n-i
	if d[a[i]]:
		d[a[i]] = min(d[a[i]], x)
	else:
		d[a[i]] = x

ans = inf

for i in xrange(n):
	if d[k-a[i]] and a[i] != k-a[i]:
		ans = min(ans, max(d[k-a[i]], d[a[i]]))

print -1 if ans == inf else ans