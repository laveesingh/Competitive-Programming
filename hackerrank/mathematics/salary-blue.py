'''input
4 2
3 3 3 3
0
3
'''
from collections import deque
from fractions import gcd
I = lambda : map(int, raw_input().split())

n, q = I()
a = deque(sorted(I()))
boss = a[0]
a.popleft()
while(a and a[0] == boss):
	a.popleft()

if not a:
	for _ in xrange(q):
		print boss+input()
else:

	a = [s-boss for s in a]

	gx = reduce(gcd, a)

	for _ in xrange(q):
		x = input()
		print gcd(boss+x, gx)cd