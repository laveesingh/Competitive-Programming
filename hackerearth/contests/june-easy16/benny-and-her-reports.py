def solve(a, n, x, m):
	req = x*(n+1) - sum(a)
	if req > m: print "Impossible"
	elif req < 1: print 1
	else: print req

I = lambda : map(int, raw_input().split())

for _ in xrange(input()):
	n, m, x = I()
	a = I()
	solve(a, n, x,m)