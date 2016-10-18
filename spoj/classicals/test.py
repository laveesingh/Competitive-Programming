import random

def case():
	t = random.randint(1,100)
	print t
	for _ in xrange(t):
		n = random.randint(1,10**8)
		k = random.randint(2,10**8)
		print n,k

case()
