import random
def case():
	return ''.join([random.choice('12') for i in xrange(random.randint(1,10))])

n = random.randint(10,20)
print n
for _ in xrange(n):
	print case()
