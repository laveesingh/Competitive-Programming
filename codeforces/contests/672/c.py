from math import sqrt
INF = 10**10

def dist(x1, y1, x2, y2):
	return sqrt((x1-x2)**2 + (y1-y2)**2)

I = lambda : map(int, raw_input().split())

ax, ay, bx, by, tx, ty = I()

n = input()

arr = []
for i in xrange(n):
	arr.append(tuple(I()))

total  = 0

def solve1(arr, ax, ay, bx, by, tx, ty):
	nearest = INF
	nearesti = 0
	for i in xrange(len(arr)):
		if dist(arr[i][0],arr[i][1],ax,ay) < nearest:
			nearest = dist(arr[i][0],arr[i][1],ax,ay)
			nearesti = i
	farest = 0
	faresti = 0
	for i in xrange(len(arr)):
		if dist(arr[i][0],arr[i][1],tx,ty) > farest:
			farest = dist(arr[i][0],arr[i][1],tx,ty)
			faresti = i
	if nearest+dist(arr[nearesti][0],arr[nearesti[1]], tx, ty) < 
