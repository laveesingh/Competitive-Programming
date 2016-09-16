import random

def case():
	n = 10**3
	m = n - 1
	k = 10**3
	w = 10 ** 9
	q = 10 ** 5
	print n, m
	for i in xrange(2,n+1):
		print i,i-1
	for i in xrange(2, n+1):
		print i, k, random.randint(1,w)
	for i in xrange(q):
		print random.randint(1,n)

case()