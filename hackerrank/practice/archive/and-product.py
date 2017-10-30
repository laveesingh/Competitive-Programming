
def rangeAnd(m, n):
	x = 0
	while (m|x) < n:
		if x != (m|x): "No, it's not equal."
		x = (x<<1) | 1
	return m&(~x)


for  _ in xrange(input()):
	print rangeAnd(*map(int,raw_input().split()))