'''input
8 8
0 0 1 0 0 1 1 0
'''

import sys
I = lambda : map(int, raw_input().split())
n, k = I()
a = I()
i = 0
E = 100
i = (i+k)%n
if i == 0:
	if a[i]: print E-3
	else:
		print E-1
	sys.exit(0)
E -= 1
if a[i]:
	E -= 2
while i != 0:
	i = (i+k)%n
	E -= [1,3][a[i]]
print E