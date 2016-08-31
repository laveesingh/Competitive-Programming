'''input
1 1 1
1
'''
I = lambda : map(int, raw_input().split())
n, b, d = I()
a = I()


waste = 0
cnt = 0
for i in xrange(n):
	if a[i] > b:
		None
	else:
		waste += a[i]
		if waste > d:
			cnt += 1
			waste = 0
print cnt