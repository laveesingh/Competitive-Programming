# import numpy
mod = 786433

n = input()
a = map(int,raw_input().split())

# p = numpy.poly1d(a[::-1])

q = input()

for _ in xrange(q):
	x = input()
	# print p(x)%mod
	ans = 0
	for j in xrange(n+1):
		ans = (ans + a[j]*pow(x, j, mod))%mod
	print ans

