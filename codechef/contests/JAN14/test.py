import random

def case():
	t =random.randint(1,100)
	print t
	for i in xrange(t):
		n = random.randint(1,10**3)
		print n
		for _ in xrange(n):
			print random.randint(1,10**18),
		print
		print random.randint(1,10**18), random.randint(1,10**18), random.randint(1000,100**9)
		print ''.join([random.choice(['A', 'M', 'R']) for i in xrange(n)])
case()