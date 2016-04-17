from fractions import gcd
from functools import reduce

def solve(a, b):
	if a == b: return a
	if b-a < 100000:
		return reduce(gcd, range(a,b))
	return 1
print (solve(*map(int, input().split())))