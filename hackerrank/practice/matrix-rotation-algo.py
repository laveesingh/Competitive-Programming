from collections import deque

def lin(a, m, n):
	"""This function will take a matrix of m*n dimensions, and will give a two dimensional array, which is linearized in its layers."""
	nol = min(n, m)/2 #no of layers in the matrix
	temp = deque()
	startx = 0
	starty = 0
	while startx < nol:
		temp2 = deque()
		x = startx
		y = starty
		while x < m-startx:
			temp2.append(a[x][y])
			# print "stuck in here>", x
			x += 1
		x -= 1
		temp2.pop()
		while y < n-starty:
			temp2.append(a[x][y])
			# print "Entered1"
			y += 1
		y -= 1
		temp2.pop()
		while x >= startx:
			# print "Entered2"
			temp2.append(a[x][y])
			x -= 1
		x += 1
		temp2.pop()
		while y >= starty:
			# print "Entered3"
			temp2.append(a[x][y])
			y -= 1
		y += 1
		temp2.pop()
		startx += 1
		starty += 1
		temp.append(temp2)
	return temp

def rotate(a, k):
	"""This function takes a queue and rotates it k times, and returns it."""
	k %= len(a)
	while k:
		val = a.pop()
		a.appendleft(val)
		k -= 1
	return a

def form(a, m, n):
	temp = [[0 for i in xrange(n)] for j in xrange(m)]
	startx = 0
	starty = 0
	nol = min(m, n)/2
	while startx < nol:
		x = startx
		y = starty
		i = 0
		# print "iteration: ",startx+1
		try:
			while x < m-startx:
				# print "x",x,"y",y,"val:",a[startx][i],"i",i
				temp[x][y] = a[startx][i]
				i += 1
				x += 1
			x -= 1
			# i -= 1
		except IndexError:
			print "Error retrieving index: ", i
			# exit()
		# print "first loop done."
		try:
			y += 1
			while y < n-starty:
				# print "x",x,"y",y,"val:",a[startx][i],"i",i
				temp[x][y] = a[startx][i]
				i += 1
				y += 1
			# i -= 1
			y -= 1
		except IndexError:
			print "Error 1 retrieving index: ",i
			# exit()
		# print "second loop done."
		try:
			x -= 1
			while x >= startx:
				# print "x",x,"y",y,"val:",a[startx][i],"i",i
				temp[x][y] = a[startx][i]
				i += 1
				x -= 1
			# i -= 1
			x += 1
		except IndexError:
			print "Error 2 retrieving index: ",i
			# exit()
		# print "Third loop done."
		try:
			y -= 1
			while y >= starty:
				# print "x",x,"y",y,"val:",a[startx][i],"i",i
				temp[x][y] = a[startx][i]
				i += 1
				y -= 1
			y += 1
		except IndexError:
			None
			# print "Error 3 retrieving index: ",i
			# exit()
		startx += 1
		starty += 1

	return temp


I = lambda: map(int, raw_input().split())

def Print(a):
	for s in a:
		for t in s:
			print t,
		print


def Main():
	m, n, k = I()
	a = []
	for i in xrange(m):
		a.append(I())
	# print "a:\n",a
	b = lin(a,m, n)
	# print "b:\n",b
	# print "rotating: ",
	for i in xrange(len(b)):
		# print "b[i]:",b[i],
		b[i] = rotate(b[i], k)

	# print "\nrotated b:\n",b
	c = form(b, m,n)
	# print "c:\n",c
	Print(c)

if __name__ == '__main__':
	Main()