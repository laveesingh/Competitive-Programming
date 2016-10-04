import random

def build(node, a, b, st, en):
	if st == en:
		b[node] = a[st]
		return
	build(2*node, a, b, st, (st+en)/2)
	build(2*node+1, a, b, (st+en)/2 + 1, en)
	b[node] = min(b[2*node], b[2*node+1])

def case():
	n = random.randint(0,3)
	n = 2**n
	a = set()
	while len(a) < n:
		a.add(random.randint(-10**1, 10**1))
	a = list(a)
	b = [0] * (2*n)
	build(1, a, b, 0, n-1)
	print n
	# flag = input()
	# if flag == 1:
	# 	b[random.randint(1,n)] = 255
	for i in xrange(1,2*n):
		print b[i],
	print 

case()