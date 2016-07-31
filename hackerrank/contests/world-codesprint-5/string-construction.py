

def solve(a):
	return len(set(a))

n = input()
for _ in xrange(n):
	a = raw_input()
	print solve(a)