import sys
from math import *

def solve(x, k):
	seglen = float(x)/pow(2,floor(log(k,2))+1)
	shift = int(floor(log(k,2)))
	# print "shift:",shift,
	sec = ~(1 << shift)
	# print "sec:",sec,
	ind = k & sec
	# print "ind:",ind
	return seglen + 2*seglen*ind

for _ in xrange(input()):
	x, k = map(int, raw_input().split())
	print "%0.6f"%solve(x,k)
 
