t = input()

for _ in xrange(t):
	n = input()
	a = map(int, raw_input().split())
	ans = 0
	for i in xrange(1,n+1):
		for j in xrange(0,n-i+1):
			# print "Adding: ", a[j:i+j]
			ans ^= reduce(int.__xor__, a[j:i+j])
	print ans