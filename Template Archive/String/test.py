import random, string
letters = string.lowercase + ","

def case():
	t = random.randint(1, 100)
	print t
	for _ in xrange(t):
		n = random.randint(100000, 1000000)
		print ''.join(random.choice(letters) for __ in xrange(n))

case()