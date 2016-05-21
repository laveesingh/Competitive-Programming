
a = set()
i, j = 0,1
while i < 10**10:
	a.add(i)
	i, j = j, i+j

t = input()
for _ in xrange(t):
	n = input()
	if n in a:
		print "IsFibo"
	else:
		print "IsNotFibo"