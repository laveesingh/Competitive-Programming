

for _ in xrange(input()):
	n = input()
	a = []
	for i in xrange(n-1):
		x, y, z = map(int, raw_input().split())
		a.append(z)
	print max(a)
	for j in xrange(n-1):
		print 0