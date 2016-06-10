from fractions import gcd

def solve(a, b, c, d):
	t = abs(gcd(c,-d))
	if a > b:
		a, b = b, a
	n = (b-a)/t
	# print "n:",n
	if n == 0:
		return min((b-a), abs((n+1)*t +(a-b)))
	return min((b-a), abs(n*t+(a-b)), abs((n+1)*t+(a-b)))


I = lambda : map(int, raw_input().split())

for _ in xrange(input()):
	a, b, c, d = I()
	print solve(a,b,c,d)

# def case():
# 	t = randint(1,20)
# 	print t
# 	for _ in xrange(t):
# 		for __ in xrange(4):
# 			print randint(1,20),
# 		print