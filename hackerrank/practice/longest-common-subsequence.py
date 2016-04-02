
def solve(a, b):
	m = len(a)
	n = len(b)
	L = [[0 for i in xrange(n+1)]for j in xrange(m+1)]
	for i in xrange(1, m+1):
		for j in xrange(1, n+1):
			if a[i-1] == b[j-1]:
				L[i][j] = L[i-1][j-1] + 1
			else:
				L[i][j] = max(L[i-1][j], L[i][j-1])
	rans = []
	i = m
	j = n
	while i > 0 and j > 0:
		if a[i-1] == b[j-1]:
			rans.append(a[i-1])
			i -= 1
			j -= 1
		else:
			if L[i-1][j] > L[i][j-1]:
				i -= 1
			else:
				j -= 1
	return rans

I = lambda : map(int, raw_input().split())
m, n = I()
a = I()
b = I()
for s in solve(a, b)[::-1]:
	print s,
print