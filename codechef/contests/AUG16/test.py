import random

def case():
	t = 100
	print t
	for _ in xrange(t):
		n = random.randint(1,10)
		print n
		for __ in xrange(n):
			print random.randint(1,10000),random.randint(1,10000)
case()