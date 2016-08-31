from random import *

opt = ['A', 'A', 'A', 'Q', 'R']

def case():
	t = 5
	print t
	for _ in xrange(t):
		n = 100
		print n
		for __ in xrange(n):
			x = choice(opt)
			if x == 'A':
				print x, randint(1,100)
			else:
				print x

case()
