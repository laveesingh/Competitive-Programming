import random

def case():
	t = random.randint(1,10)
	print t
	for _ in xrange(t):
		n = 1
		print n
		ai = None
		for _ in xrange(n):
			ai = [random.randint(1,10000) for i in xrange(random.randint(1,200))]
			print len(ai),
			for s in ai: print s,
			print
		if random.choice([0,1]):
			for s in ai[::-1]: print s,
			print
		else:
			for s in ai: print s,
			print

case()