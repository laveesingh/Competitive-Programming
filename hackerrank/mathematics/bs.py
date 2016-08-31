
def bs(a, x):
	n = len(a)
	lo = 0
	hi = n-1
	mid = 0
	while lo <= hi:
		print "mid: ", mid
		mid = (lo + hi)/2
		if (a[mid] < x): lo = mid
		elif (a[mid] > x): hi = mid
		else: return mid
	if a[lo] == x: return lo
	return -1

a = [0, 1, 3, 4, 6, 9]

print bs(a,1)
print bs(a,2)
print bs(a,8)
print bs(a,9)

