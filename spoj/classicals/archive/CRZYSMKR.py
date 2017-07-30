
def solve(n):
	x = pow(34, n%10, 11) + 30*n + 32
	x %= 11
	return (11-x)%11

import sys

inputs = sys.stdin.read()
inputl = inputs.split()


for i in xrange(1,int(inputl[0])+1):
	n = int(inputl[i])
	print solve(n)