from random import *

def case():
	t = 3
	print t
	for i in xrange(t):
		n = randint(1,10)
		print n
		for j in xrange(n):
			print randint(0,n-1-j),
		print

case()