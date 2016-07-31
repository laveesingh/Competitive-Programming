import random

def case():
	t = random.randint(1,100)
	print t
	for _ in xrange(t):
		n = random.randint(5,20)
		print n
		for i in xrange(n):
			for j in xrange(n):
				print random.randint(0,1000),
			print
case()