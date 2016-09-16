import random

def case():
	n = random.randint(1,10**5)
	m = random.randint(n-1,10**5)
	w = 10**9
	q = 10**5
	print n,m
	nodes = range(2,n+1)
	random.shuffle(nodes)
	nodes = [1]+nodes
	for i in xrange(1,n):
		j = random.randint(0,i-1)
		print nodes[i],nodes[j]
	tickets  = []
	for i in xrange(n-1):
		tickets.append((i+2, random.randint(n/10+1,n), random.randint(1,w)))
	for i  in xrange(m-n+1):
		tickets.append((random.randint(n/10+1,n), random.randint(1,n), random.randint(1,w)))
	random.shuffle(tickets)
	for s in tickets:
		for t in s:
			print t,
		print
	print q
	for _ in xrange(q):
		print random.randint(1,n)


case()
