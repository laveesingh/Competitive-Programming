import sys
limit = 20 # this is to be 200001


I = lambda : map(int,raw_input().split())

n, m = I()

def power(n, i):
	if i == 0:
		return 1
	if i == 1:
		return n
	if i%2:
		return n*power(n,i-1)
	x = power(n, i/2)
	return x*x

def add(a, b):
	m = max(len(a), len(b))
	c = ["0"]*m
	a = a.zfill(m)
	b = b.zfill(m)
	j = m-1
	carry = 0
	while j >= 0:
		if(carry == 0):
			if(a[j] == "1" and b[j] == "1"):
				carry = 1
			elif (a[j] == "1" or b[j] == "1"):
				c[j] = "1"
		elif carry == 1:
			if (a[j] == "1" and b[j] == "1"):
				carry = 1
				c[j] = "1"
			elif a[j] == "1" or b[j] == "1":
				None
			else:
				carry = 0
				c[j] = "1"
		j -= 1
	c = ''.join(c)
	if carry == 1:
		c = "1"+c
	return c



dist = [[("1"+"0"*limit) for i in xrange(n+1)] for j in xrange(n+1)]

def lt(a, b):
	for i in xrange(len(a)):
		if a[i] < b[i]:
			return True
		elif a[i] > b[i]:
			return True
		if i == len(a)-1:
			return True
		if i == len(b) -1:
			return False

for edge in xrange(m):
	x, y, z = I()
	dist[x][y] = "1"+"0"*z
	dist[y][x] = "1"+"0"*z

for k in xrange(1,n+1):
	for i in xrange(1,n+1):
		for j in xrange(1, n+1):
			temp = add(dist[i][k], dist[k][j])
			if (lt(temp, dist[i][j])):
				dist[i][j] = temp

for s in dist:
	print s

ans = "0"
for i in xrange(1,n+1):
	for j in xrange(i+1,n+1):
		ans = add(ans, dist[i][j])
print ans