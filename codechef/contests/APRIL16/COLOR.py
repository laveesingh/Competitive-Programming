
def solve(a):
	n = len(a)
	r, g, b = 0, 0, 0
	for s in a:
		if s == "R":
			r += 1
		elif s == "G":
			g += 1
		else:
			b += 1
	return n - max(r, g, b)

for _ in xrange(input()):
	n  = input()
	a = raw_input()
	print solve(a)