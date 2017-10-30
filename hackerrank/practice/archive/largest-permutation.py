from collections import defaultdict
import sys

def solve(a, n, k):
	# print "Initial length of a: ", len(a)
	ind = defaultdict(int)
	for i, s in enumerate(a):
		ind[s] = i
	mx = n
	curi = 0
	while k > 0 and mx > 0:
		mxindex = ind[mx]
		if mxindex == curi: k += 1
		a[curi], a[mxindex] = a[mxindex], a[curi]
		ind[mx] = curi
		ind[a[mxindex]] = mxindex
		k -= 1
		mx -= 1
		curi += 1
	return a

I = lambda : map(int, raw_input().split())

n, k = I()
raw = sys.stdin.read()
a = map(int, raw.split())
for s in solve(a, n, k):
	print s,
print
