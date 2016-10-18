n = input()
def dist(x, y):
	return (x[0]-y[0])**2 + (x[1]-y[1])**2
points = []
ans = 0
for _ in xrange(n):
	point = map(int, raw_input().split())
	for xy in points:
		ans = max(ans, dist(xy, point))
	print ans
	points.append(point)

