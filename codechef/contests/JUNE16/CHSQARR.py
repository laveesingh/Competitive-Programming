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

# def case(n, m, q):
# 	# n, m = randint(1,50), randint(1,50)
# 	# n, m = 100,100
# 	# print n,m
# 	string = ""
# 	string+=str(n)+'\n'+str(m)+'\n'
# 	for i in xrange(n):
# 		for j in xrange(m):
# 			# print randint(1,1000),
# 			string += str(randint(1,1000))+" "
# 		string += "\n"
# 	# q = randint(1,20)
# 	# q = 50
# 	# print q
# 	string += str(q)+'\n'
# 	for _ in xrange(q):
# 		x = randint(1,n)
# 		y = randint(1,m)
# 		# print x,y
# 		string += str(x) + " " + str(y) + "\n"
# 	f = open("input.txt", 'w+')
# 	f.write(string)
# 	f.close()