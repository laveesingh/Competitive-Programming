# 1 
# 3 3 
# 0 1000000000 500000000 
# Ans: 500000000 

# Also check for repetitive values: 
# 1 
# 10 3 
# 1 2 9 8 4 4 8 9 2 1 
# Ans: 3 


# input: 
# 6 
# 10 3 
# 1 2 9 8 4 4 8 9 2 1 
# 5 3 
# 1 2 8 4 9 
# 20 3 
# 9 8 7 10 6 5 4 3 2 1 19 18 17 16 15 14 13 12 11 20 
# 3 3 
# 0 1000000000 500000000 
# 20 4 
# 9 8 7 10 6 5 4 3 2 1 19 18 17 16 15 14 13 12 11 20 
# 20 5 
# 9 8 7 10 6 5 4 3 2 1 19 18 17 16 15 14 13 12 11 20 
# output: 
# 3 
# 3 
# 9 
# 500000000 
# 6 
# 4

def solve():
	n, c = map(int, raw_input().split())
	points = []
	for _ in xrange(n):
		points.append(input())
	points.sort()
	distance = []
	distance.append(0)
	for i in xrange(1,len(points)):
		distance.append(points[i]-points[i-1])
	print "points:",points
	print "distance:",distance
	lo = min(distance) # lower bound of the distance
	hi = sum(distance) # upper bound of the distance
	print "lo:",lo,"hi:",hi
	mins = []
	while lo < hi:
		x = lo + (hi-lo)/2
		print "x:",x
		req = 1 # required cows
		curl = 0 # current distance

		for i in xrange(n):
			if curl + distance[i] <= x:
				curl += distance[i]
			else:
				req += 1
				curl = distance[i]
		if req == c:
			mins.append(x)
			hi = x
		elif req < c:
			hi = x
		else:
			lo = x + 1
	return max(lo, max(mins))

print solve()