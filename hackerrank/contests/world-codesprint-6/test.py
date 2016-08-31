import random
r = random.randint
def case():
	t = random.randint(1,1000)
	print t
	for _ in xrange(t):
		print r(1,25),r(1,25),r(1,20)

case()