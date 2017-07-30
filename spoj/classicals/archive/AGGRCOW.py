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

import sys

def fits(a, n):
	cows = 1;
	dist = 0
	for i in xrange(1, len(a)):
		dist += a[i]-a[i-1]
		if dist >= n:
			cows += 1
			dist = 0
			if cows == c:
				# print "fits -> a:",a,"n:",n
				return 1
	return 0

def solve(a, n, c):
	a.sort()
	low = 0
	high = a[-1]
	mx = -1
	while low < high:
		cur = low + (high-low)/2
		if (fits(a, cur)):
			if cur > mx:
				mx = cur
			low = cur + 1
		else:
			high = cur 

	return mx

	


inputs = sys.stdin.read().split("\n")
i = 1
for _ in xrange(int(inputs[0])):
	# n, c = map(int, raw_input().split())
	n, c = map(int, inputs[i].split())
	i += 1
	a = []
	for __ in xrange(n):
		a.append(int(inputs[i]))
		i += 1
	print solve(a, n, c)




