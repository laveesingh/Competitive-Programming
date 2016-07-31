

cubes = [0]*100001
for i in xrange(100001):
	cubes[i] = i*i*i

def binary_search(n):
	lo = 0
	hi = 100001
	global cubes
	prev =0
	mid = 0
	while lo <= hi:
		print "lo:",lo,"hi:",hi, "mid: ",mid
		mid = lo + (hi-lo)/2
		if mid == prev:
			break
		prev = mid
		if (cubes[mid] > n): hi = mid-1
		else: lo = mid
	return lo


def process(n):
	print "Processing for: ", n
	blocks = 0
	index = 0
	while n > 0:
		index = binary_search(n)
		print "Found: ", i
		blocks += n/cubes[index]
		n %= cubes[index]
	return blocks

m = input()

limit = max(0, m-100001)
maxb = 0
maxx = 0
for i in xrange(m, limit, -1):
	blocks = process(i)
	if blocks > maxb:
		maxb = blocks
		maxx = i
	elif blocks == maxb:
		if i > maxx:
			maxx = i

print maxb, maxx