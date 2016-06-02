from collections import defaultdict

MOD = 10**9+9

coeff = defaultdict(int)
k = None
bases = None

def mult(a, b):
	"""returns multiplication of matrix a and matrix b"""
	global k
	c = [[0 for i in xrange(k)] for j in xrange(k)]
	for i in xrange(k):
		for j in xrange(k):
			for x in xrange(k):
				c[i][j] += a[i][x]*b[x][j]
				c[i][j] %= MOD
	return c

def power(a,p):
	if (p == 1): return a
	if (p%2):
		return mult(a,power(a,p-1))
	X = power(a,p/2)
	return mult(X,X)

def fib(n):
	global bases, coeff,k
	# print "n:",n,"k:",k
	if n < k:
		return bases[n]
		
	n = n-k+1 # Something suspicious here
	V = [bases[k-i-1] for i in xrange(k)]
	T = [[0 for i in xrange(k)] for j in xrange(k)]
	for i in xrange(k):
		T[0][i] = coeff[i+1]
	for i in xrange(1,k):
		for j in xrange(k):
			if j == i-1:
				T[i][j] = 1
			else:
				T[i][j] = 0
	T = power(T,n)
	# print T
	return T[0][0]

def process_raw(a):
	global k, bases, coeff
	a = a[7:]
	k = int(a[-2])
	a = a.split(' + ')
	for s in a:
		if s[0] == 'f':
			coeff[int(s[-2])] = 1
		else:
			# print s,'splitted',s.split('f')
			coeff[int(s[-2])] = int(s.split('f')[0])

# a = raw_input().strip()
# process_raw(a)
# bases = map(int, raw_input().split())
# q = int(raw_input())

import sys

inputs = sys.stdin.read().split("\n")
a = inputs[0].strip()
process_raw(a)
bases = map(int, inputs[1].split())
q = int(inputs[2])
l = inputs[4:]
ans = []
for i in xrange(len(l)):
	if l[i]:
		print "solving for ",l[i]
		ans.append(str(fib(int(l[i]))))
print '\n'.join(ans)