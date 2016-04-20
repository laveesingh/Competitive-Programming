
def solve(a, n):
	for i in xrange(3):
		a[1][i] += a[0][1];
	for i in xrange(2,n):
		for j in xrange(3):
			if j == 0:
				a[i][j] += min(a[i-1][j],a[i-1][j+1])
			elif j == 2:
				a[i][j] += min(a[i-1][j],a[i-1][j-1])
			else:
				a[i][j] += min(a[i-1][j],a[i-1][j-1],a[i-1][j+1])
	# for s in a:
	# 	print s
	return a[n-1][1]
test = 1
import sys
inputs = sys.stdin.read()
inputs = inputs.split("\n")
line = 0
while 1:
	n = int(inputs[line])
	line += 1
	if n == 0: break
	a = []
	for i in xrange(n):
		a.append(map(int, inputs[line].split()))
		line += 1
	print "%d. %d"%(test,solve(a,n))
	test += 1