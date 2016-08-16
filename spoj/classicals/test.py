from random import *

opt = ['A', 'A', 'A', 'Q', 'R']

def case():
	t = 25
	print t
	for _ in xrange(t):
		n = 100000
		print n
		for __ in xrange(n):
			x = choice(opt)
			if x == 'A':
				print x, randint(1,10000)
			else:
				print x

case()
