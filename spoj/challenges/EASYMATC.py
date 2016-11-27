from fractions import gcd
ai = lambda : map(int, raw_input().split())

n, m, x, y = ai()
a = [x, x+y, x+2*y, x+3*y, x+4*y]

def divs(n):
	ans = 0
	for mask in xrange(1,2**5):
		binmask = bin(mask)[2:].zfill(5)
		denom = 1
		cnt = 0
		g = None
		for i in xrange(5):
			if binmask[i] == '1': g=a[i]

		for i in xrange(5):
			if binmask[i] == '1':
				cnt += 1
				denom *= a[i]
				g = gcd(g, a[i])
		if cnt%2:
			if denom <= n:
				print "including ",denom, "with",n/denom
			ans += n/denom
		else:
			denom = denom
			if denom <= n:
				print "excluding ",denom, "with", n/denom
			ans -= n/denom
	return ans

print divs(m) - divs(n-1)
