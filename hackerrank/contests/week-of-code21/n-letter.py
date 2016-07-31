from math import acos, sqrt, pi
from itertools import permutations

def orientation(a, b, c):
	"""
	-1 => counter clock wise
	1 => clockwise
	"""
	val = (b[1]-a[1])*(c[0]-b[0]) - (b[0]-a[0])*(c[1]-b[1])
	if val == 0: return 0
	if val > 0:
		return 1
	return -1

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
				# print a, b, c, d
				tod = 0
				for perm in permutations((a, b, c, d)):
					ai, bj, ck, dl = list(perm)
					# print ai, bj, ck, dl
					# print "orientation a, b, c: ", orientation(ai, bj, ck), "orientation b,c,d:",orientation(bj,ck,dl)
					if orientation(ai, bj, ck) == 1 and orientation(bj,ck,dl) == -1 and isangle(ai,bj,ck) and isangle(bj,ck,dl):
						# print "Here"
						tod += 1
				count += tod/2

print count

# a=(2, 0)
# b=(2,2)
# c=(0,0)
# print orientation(a, b, c)