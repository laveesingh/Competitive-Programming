from collections import defaultdict
import string

def solve(a, b):
	ad = defaultdict(int)
	bd = defaultdict(int)
	for s in a:
		ad[s] += 1
	for s in b:
		bd[s] += 1
	alphs = string.lowercase
	for s in alphs:
		if ad[s] and bd[s]:
			return True
	return False


for _ in xrange(input()):
	a = raw_input()
	b = raw_input()
	print "Yes" if solve(a, b) else "No"
