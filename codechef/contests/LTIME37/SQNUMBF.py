from math import sqrt
from operator import mul
t = input()

for _ in xrange(t):
	n = input()
	a = map(int, raw_input().split())
	x = reduce(mul, a)
	for i in xrange(2,int(sqrt(x))+1):
		if(x % (i*i) == 0):
			print i
			break

# def case():
# 	t = randint(1,10)
# 	print t
# 	for _ in xrange(t):
# 		n = randint(1,20)
# 		print n
# 		for i in xrange(n):
# 			print randint(400,10000)/16,
# 		print