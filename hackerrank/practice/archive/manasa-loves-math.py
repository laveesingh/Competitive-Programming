from itertools import permutations

def isin(a, b):
	for s in a:
		if b.count(s) < a.count(s):
			return False
	return True

def solve(n):
	a = str(n)
	if(len(a) <= 3):
		for s in permutations(a):
			if(int(''.join(s))%8 == 0):
				return True
		return False
	else:
		table = []
		for i in xrange(1,126):
			table.append(str(i*8).zfill(3))
		for elem in table:
			if isin(elem, a):
				return True
		return False



for _ in xrange(input()):
	print "YES" if solve(input()) else "NO"