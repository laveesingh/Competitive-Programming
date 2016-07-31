from collections import deque

n = input()
a = map(int, raw_input().split())
d = {i:deque() for i in xrange(1,5)}
for i in xrange(len(a)):
	d[a[i]].append(i+1)
	d[a[i]] = deque(sorted(d[a[i]]))

fixi = 0

N = n
while 1:
	if len(a) <= fixi:
		break
	if a[fixi] == n:
		n -= 1
		fixi += 1
	else:
		x = a.pop()
		maxn = n-1
		while maxn in a:
			

if n in a and a[fixi] == n:
	n -= 1
	fixi += 1
else:
	# either n will be at bottom of a, or n won't be in a
	if n in b:
		x = b.pop()
		while x != n:

