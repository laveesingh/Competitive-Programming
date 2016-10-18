import random

def case():
	n, m = random.randint(1, 20), random.randint(1,100)
	print n, m
	for _ in xrange(n):
		print random.randint(1,20),
	print

case()
