from math import acos,sqrt
class point:
	def __init__(self, a, b, c):
		self.x = a
		self.y = b
		self.z = c
	def __repr__(self):
		return "%di + %dj + %dk"%(self.x, self.y, self.z)

def abs_val(a):
	return sqrt(a.x ** 2 + a.y ** 2 + a.z ** 2)

def angle(a, b, c):
	ba = point(b.x-a.x, b.y-a.y, b.z-a.z)
	bc = point(b.x-c.x, b.y-c.y, b.z-c.z)

	return acos((ba.x*bc.x + ba.y*bc.y + ba.z*bc.z)/(abs_val(ba)*abs_val(bc)))

points = []
for _ in xrange(input()):
	points.append(point(*map(int, raw_input().split())))

answers = []
for i in xrange(len(points)):
	for j in xrange(i+1,len(points)):
		for k in xrange(j+1,len(points)):
			answers.append(angle(points[i], points[j], points[k]))

# print answers
print sum(answers)/len(answers)