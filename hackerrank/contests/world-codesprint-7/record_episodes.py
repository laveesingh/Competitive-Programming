
a = None
L = None
R = None

def put(xy, interval):
	x = xy[0]
	y = xy[1]
	for i in xrange(x,y+1):
		if interval[i] == 1:
			return 0
	return 1

def doput(xy, interval):
	x = xy[0]
	y = xy[1]
	for i in xrange(x,y+1):
		interval[i] = 1

def unput(xy, interval):
	x = xy[0]
	y = xy[1]
	for i in xrange(x,y+1):
		interval[i] = 0

def solve(i, interval, l, r):
	'''interval is an array of 0s and 1s.
	0 indicate empty moment and 1 indicate occupied moment.'''
	global R, L, a
	if i >= len(a): return 
	f1 = put(a[i][0], interval[:])
	f2 = put(a[i][1], interval[:])
	if f1 and f2:
		I1 = interval[:]
		I2 = interval[:]
		doput(a[i][0], I1)
		solve(i+1, I1, l, r+1)
		# unput(a[i][0], interval)
		doput(a[i][1], I2)
		solve(i+1, I2, l, r+1)
	elif f1:
		doput(a[i][0], interval)
		solve(i+1, interval, l, r+1)
	elif f2:
		doput(a[i][1], interval)
		solve(i+1, interval, l, r+1)
	if f1 or f2:
		if r-l > R-L:
			L = l
			R = r


q = int(raw_input())

for _ in xrange(q):
	a = []
	n = int(raw_input())
	maxTime = 0
	for __ in xrange(n):
		x,y,z,w = map(int, raw_input().split())
		a.append(((x,y), (z,w)))
		maxTime = max(maxTime, x, y, z, w)
	L = 0
	R = 0
	FL, FR = 0, 0
	for i in xrange(len(a)-1):
		interval = [0]*(maxTime+1)
		# print interval
		solve(i, interval, 0, 0)
		if R-L > FR-FL:
			FL = L
			FR = R
	print FL+1, FR+1
