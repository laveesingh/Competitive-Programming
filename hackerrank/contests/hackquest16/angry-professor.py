I = lambda : map(int, raw_input().split())
for _ in xrange(input()):
	n, k = I()
	a = I()
	b = filter(lambda x: x <= 0, a)
	print "NO" if len(b) >= k else "YES"