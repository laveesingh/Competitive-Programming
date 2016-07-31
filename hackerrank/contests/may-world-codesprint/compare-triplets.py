I = lambda : map(int, raw_input().split())

a = I()
b = I()
al = 0
bo = 0
for i in xrange(3):
	if a[i] > b[i]:
		al += 1
	elif b[i] > a[i]:
		bo += 1
print al, bo
