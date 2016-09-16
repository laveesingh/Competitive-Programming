import random
import string

def case():
	t = random.randint(1,10)
	print t
	for _ in xrange(t):
		x = random.randint(10**8,10**9)
		k = random.randint(10**11,10**12)
		print x,k

case()	
