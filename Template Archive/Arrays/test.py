import random

def case():
	n = random.randint(10**5, 2 * 10**5)
	print n
	for _ in xrange(n):
		print random.randint(1,10**5),
	print
case()