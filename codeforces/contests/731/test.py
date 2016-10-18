
import random
def case():
	n = random.randint(2,10)
	m = random.randint(1,6)
	k = random.randint(1,n)
	print n, m, k	
	for _ in xrange(n):
		print random.randint(1,k),
	print
	for _ in xrange(m):
		x = random.randint(1,k)
		y = random.randint(1,k)
		if x == y:
			if x > 1:
				x -= 1
			else: x += 1
		print x,y
case()