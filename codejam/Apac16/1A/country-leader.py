
def solve(a):
	b = []
	maxlet = 0
	for s in a:
		x = [t for t in set(s) if t!=' ']
		maxlet = max(maxlet, len(x))
	for s in a:
		x = [t for t in set(s) if t!= ' ']
		if len(x) == maxlet:
			b.append(s)
	b.sort()
	return b[0]

for _ in xrange(int(raw_input())):
	n = int(raw_input())
	a = []
	for i in xrange(n):
		a.append(raw_input())
	print "Case #%d: %s"%(_+1, solve(a))