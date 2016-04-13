def solve(a):
	for i in xrange(len(a)):
		a[i].sort()
	for i in xrange(len(a)):
		for j in xrange(1,len(a)):
			if a[j][i] < a[j-1][i]:
				return False
	return True

for _ in xrange(input()):
	n = input()
	a=[]
	for i in xrange(n):
		a.append(list(raw_input()))
	print "YES" if solve(a) else "NO"