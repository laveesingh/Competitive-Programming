from math import factorial as f

def test(n, k):
	x = f(n)
	power = 0
	while x % (k**power) == 0:
		power += 1
	return power -1

for _ in xrange(input()):
	n, k = map(int, raw_input().split())
	print "Case %d: %d"%(_+1,test(n,k))
