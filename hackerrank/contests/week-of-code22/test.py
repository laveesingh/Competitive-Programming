import random

def case():
	n = random.randint(10,20)
	print n+3
	for i in xrange(3):
		print '+',random.randint(1,7)
	for _ in xrange(n):
		sign = random.choice(['+','-'])
		if sign == '+':
			print sign, random.randint(1, 7)
		else:
			print '-'
case()