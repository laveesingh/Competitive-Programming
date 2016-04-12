
a = [0]*12
n = input()
i = 0
for i in xrange(12):
	x = raw_input().split()
	x = int(x[1])
	a[i] = x

for i in xrange(n-12):
	x = raw_input().split()[1]
	a[i%12] = int(a[i%12]*0.45) + int(int(x)*0.55)

for i in xrange(12):
	print a[(n+i)%12]