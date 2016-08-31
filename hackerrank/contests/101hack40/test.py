import random

def case():
	n = 10
	m = 5
	print n
	for _ in xrange(n):
		print random.randint(1,10),
	print
	print m
	x = [random.randint(1,10) for i in xrange(m)]
	for s in sorted(x):
		print s,
	print
case()