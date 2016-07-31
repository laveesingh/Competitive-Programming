
t = int(raw_input())

for _ in xrange(t):
	n = int(raw_input())
	a = map(int, raw_input().split())
	ans = 0
	for i in xrange(len(a)):
		for j in xrange(i+1,len(a)+1):
			b = a[i:j]
			# print "b:",b
			if sum(b)%2 == 0:
				ans = max(ans, len(b))
	print ans
