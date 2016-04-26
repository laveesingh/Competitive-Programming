
n, p = map(int, raw_input().split())

def sos(n):
	a = 0.5
	r = 0.5
	nom = (1-r**n)
	nom *= a
	den = (1-r)
	return nom/den

a = []
for _ in xrange(n):
	a.append(raw_input())

xn = a.count("halfplus") * 0.5
xd = 1 - sos(len(a))
x = xn / xd

ans = 0
i= 0
while x > 0:
	tx = x
	if x%2 == 1:
		x -= 0.5
	ans += (x/2 * p)
	

# from fractions import Fraction
# for _ in xrange(10):
# 	print Fraction(sos(input()))