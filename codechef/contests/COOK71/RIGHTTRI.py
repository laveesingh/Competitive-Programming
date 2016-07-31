
for _ in xrange(input()):
	c, s = map(float, raw_input().split())
	lo = 0.0
	hi = c
	cnt = 30
	while lo <= hi and cnt:
		mid = (hi+lo)/2
		x = (4*s*s)/(mid*mid) + (mid*mid)
		print lo,mid,hi, x, c*c
		if x < c*c:
			lo = mid
		else:
			hi = mid
		cnt -= 1
	b = lo ** 0.5
	a = (c**2 - b**2)**0.5
	print a, b, c
