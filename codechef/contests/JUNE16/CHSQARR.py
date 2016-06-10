import sys
def solve(x, y):
	global a, n, m
	mtime = sys.maxint

	for i in xrange(n-x+1):
		for j in xrange(m-y+1):
			maximum = 0
			for k in xrange(i,i+x):
				maximum = max(maximum, max(a[k][j:j+y]))
			time = 0
			for k in xrange(i,i+x):
				for l in xrange(j, j+y):
					# print a[k][l],
					time += maximum-a[k][l]
				# print
			# print
			mtime = min(mtime, time)
	return mtime
I = lambda : map(int, raw_input().split())

a = []
n, m = I()
for i in xrange(n):
	a.append(I())

q = int(raw_input())
for _ in xrange(q):
	x, y = I()
	print solve(x, y)

# def case():
# 	n, m = randint(1,50), randint(1,50)
# 	print n,m
# 	for i in xrange(n):
# 		for j in xrange(m):
# 			print randint(1,1000),
# 		print
# 	q = randint(1,20)
# 	print q
# 	for _ in xrange(q):
# 		x = randint(1,n)
# 		y = randint(1,m)
# 		print x,y