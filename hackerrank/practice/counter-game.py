from math import *

def isPower(n):
	binary = bin(n)[2:]
	return binary.count('1') == 1

def predecessor(n):
	if isPower(n):
		p = int(log(n, 2))
		p -= 1
		return 2 ** p
	binary = bin(n)[2:]
	l  = len(binary)
	l -= 1
	num = '1'+'0'*l
	return int(num, 2)

def solve(n):
	count = 0
	while n > 1:
		n -= predecessor(n)
		count += 1
	if count%2:
		print "Louise"
	else: print "Richard"

for  _ in xrange(input()):
	solve(input())