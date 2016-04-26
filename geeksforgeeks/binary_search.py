
def binary_search(a, x, key=None):
	"""We have to find the index of member x in sorted sequence "a".
	This function is useful when the sequence is sorted and we have random access to elements in the sequence.
	If the element is not found, function will return -1."""
	lo = 0
	hi = len(a)-1
	while lo <= hi:
		mid = lo + (hi-lo)/2
		if a[mid] == x:
			return mid
		if a[mid] > x:
			hi = mid-1
		else:
			lo = mid+1
	return -1

### These two functions below work in pair
def p(x):
	global a, target
	return a[x] >= target

def binary_search(lo, hi, p):
	"""This function will be implemented as abstraction of binary search,
	if for predicate function p, it evaluates to a series of false followed by a series of true,
	when applied to the closed interval [lo,hi]."""
	while lo < hi:
		mid = lo + (hi-lo)/2
		if p(mid) == True:
			hi = mid
		else:
			lo = mid + 1
	if p(lo) == False:
		# no element in the closed interval [lo,hi] evaluates to true when function p is applied.
		raise Exception("Not Found: The element you're looking for, is not in the given interal.") 
	return lo	

### These two functions below work in pair
def p(x):
	global a, target
	return a[x] <= target

def binary_search(lo, hi, p):
	"""This function will be implemented as abstraction of binary search,
	if for predicate function p, it evaluates to a series of true followed by a series of false,
	when applied to the closed interval [lo,hi]."""
	while hi > lo:
		mid = lo + (hi-lo)/2
		if p(mid) == True:
			lo = mid
		else:
			hi = mid-1
	if p(hi) == False:
		# no element in the closed interval [lo, hi] evaluates to true when function p is applied.
		raise Exception("Not Found, The element you're looking for, is not in the given interval.")
	return hi