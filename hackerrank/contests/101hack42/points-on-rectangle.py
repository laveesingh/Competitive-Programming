for _ in xrange(input()):
	n = input()
	points = []
	for _ in xrange(n):
		points.append(map(int, raw_input().split()))
	points.sort()
	maxx = points[-1][0]
	minx = points[0][0]
	points.sort(key=lambda x: x[1])
	maxy = points[-1][1]
	miny = points[0][1]
	ans = "YES"
	for s, t in points:
		if (s == maxx or s == minx) and miny <= t <= maxy: None
		elif (t == maxy or t == miny) and minx <= s <= maxx: None
		else:
			ans = "NO"
			break
	print ans
