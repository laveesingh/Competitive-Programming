def ispal(a):
	return a == a[::-1]

def solve(a):

	a = list(a)
	if ispal(a): return 1
	for i in xrange(len(a)/2):
		j = len(a) -i- 1 
		if a[i] != a[j]:
			b = a[:]
			del a[i]; del b[j]
			return ispal(a) or ispal(b)
	return 1

for _ in xrange(input()):
	print "YES" if solve(raw_input()) else  "NO"
