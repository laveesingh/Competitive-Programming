

I = lambda : map(int, raw_input().split())
n, d = I()
a  = I()

ans = 0

for i in xrange(len(a)-2):
	lo = i+1
	hi = len(a)-2
	j = None
	k = None
	while lo <= hi:
		# print "lo:",lo,"hi:",hi
		mid = lo + (hi-lo)/2
		if a[mid] - a[i] > d:
			hi = mid-1
		elif a[mid] - a[i] == d:
			j = mid
			break
		else:
			lo = mid+1
	if j or (lo < len(a) and a[lo]-a[i] == d):
		j = j if j else lo
		low = j + 1
		high = len(a)-1
		while low <= high:
			# print "low:",low,"high:",high
			mid = low + (high-low)/2
			if a[mid] - a[j] > d:
				high = mid-1
			elif a[mid]-a[j] == d:
				k = mid
				break
			else:
				low = mid+1
		if k or (low < len(a) and a[low]-a[j] == d):
			ans += 1
		else:
			continue

	else:
		continue
print ans