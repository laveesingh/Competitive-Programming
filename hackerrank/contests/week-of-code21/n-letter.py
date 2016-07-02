from math import acos, sqrt, pi
from itertools import permutations

def orientation(a, b, c):
	if a[0] == b[0] == c[0]: return 0
	if b[0] == a[0]:
		return -1
	if b[0] == c[0]:
		return 1
	sigma = float(b[1]-a[1])/float(b[0]-a[0])
	tou = float(c[1]-b[1])/float(c[0]-b[0])
	if tou > sigma: return 1
	if tou < sigma: return -1
	return 0

def isangle(a, b, c):
	angle = acos(float((a[0]-b[0])*(c[0]-b[0]) + (a[1]-b[1])*(c[1]-b[1]))/
					float(sqrt((b[0]-a[0])** 2 + (b[1]-a[1])**2) * sqrt((b[0]-c[0])** 2 + (b[1]-c[1])**2)))
	angle *= 180
	angle /= pi
	if angle > 90: return False
	return True


points = []

n = input()

for a in xrange(n):
	points.append(map(int,raw_input().split()))

count = 0

for i in xrange(len(points)-3):
	for j in xrange(i+1, len(points)-2):
		for k in xrange(j+1, len(points)-1):
			for l in xrange(k+1, len(points)):
				a = points[i]
				b = points[j]
				c = points[k]
				d = points[l]
				tod = 0
				for perm in permutations((a, b, c, d)):
					ai, bj, ck, dl = list(perm)
					if orientation(a, b, c) == -1 and orientation(b,c,d) == 1 and isangle(a,b,c) and isangle(b,c,d):
						tod += 1
				count += tod/2


