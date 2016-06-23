for _ in xrange(input()):
	a, b, x = map(int, raw_input().split())
	if b < 0:
		if a == 1:
			print 1 if x == 1 else 0
			continue
		print 0 
		continue
	atob = pow(a,b)
	t = atob/x
	if abs((t+1)*x - atob) < abs(t*x - atob):
		print (t+1)*x
	else:
		print t*x