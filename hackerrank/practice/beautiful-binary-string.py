'''input
7
0101010
'''

n = input()
a =list(raw_input())
if n <= 2:
	print 0
else:
	cnt = 0
	for i in xrange(2,n):
		if a[i] == '0' and a[i-1] == '1' and a[i-2] == '0':
			a[i] = '1'
			cnt += 1
	print cnt