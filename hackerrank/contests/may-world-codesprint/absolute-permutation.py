from collections import defaultdict
def solve(n, k):
	a = [0]*(n+1)
	f = {s:1 for s in range(1,n+1)}
	f = defaultdict(int, f)
	for i in xrange(1,n+1):
		if f[k+i] == 0 and f[i-k] == 0:
			# print "First"
			return -1
		
		if k+i <= n and (f[i-k] == 0 or i-k < 1):
			a[i] = k+i
			f[i+k] =0
		elif i-k > 0:
			a[i] = i-k
			f[i-k] = 0
		else:
			# print "Second"
			return -1
	return a[1:]

for _ in xrange(input()):
	n, k = map(int, raw_input().split())
	x = solve(n, k)
	if x == -1: print x
	else:
		for s in x: print s,
		print 



