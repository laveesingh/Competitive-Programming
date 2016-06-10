I = lambda : map(int, raw_input().split())
n = input()
a = I()
mod = 10**9 +7
for i in xrange(input()):
	q = I()
	if len(q) == 2:
		r = q[1]
		i = 0
		enj = 1
		while 1+i*r <= n:
			enj *= a[i*r]
			i += 1
		x = str(enj)
		print x[0],enj%mod
	else:
		i = q[1] - 1
		j = q[2]
		a[i] = j
