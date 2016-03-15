a = []
n = 4*10**16 + 1
i, j = 0, 1
while i < n:
	a.append(i)
	i, j = j, i+j
	

for _ in xrange(input()):
	n = input()
	cnt = 0
	for i in xrange(0, len(a), 3):
		if a[i] > n:
			break
		cnt += a[i]
	print cnt
