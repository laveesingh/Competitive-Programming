def solve(a):
	b = [0]*len(a)
	b[0] = 1
	for i in xrange(1,len(a)):
		for j in xrange(i):
			if a[i] > a[j]:
				b[i] = max(b[i], 1+b[j])
	return max(b)

a = map(int,raw_input().split())
print solve(a)