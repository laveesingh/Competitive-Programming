import random
def case(flag):
	t = random.randint(1,5)
	print t
	for _ in xrange(t):
		n, m = random.randint(1,10),random.randint(1,10)
		print n, m
		for i in xrange(n):
			x = random.randint(1,10)
			x *= 2**(random.choice([0,1]))
			x *= 5**(random.choice([0,1]))
			print x,
		print
		for i in xrange(m):
				#print i
				Type = random.choice([1,3, 3])
				if flag: Type = random.choice([Type,2])
				if Type == 1 or Type == 2:
					x = random.randint(1,n)
					y = random.randint(x,n)
					z = random.randint(1,10)
					z *= 2**(random.choice([0,1]))
					z *= 5**(random.choice([0,1]))
					print Type, x, y, z
				else:
					x = random.randint(1,n)
					y = random.randint(x,n)
					print Type, x, y
case(True) # Pass False if you don't want 2nd kind of update queries.
