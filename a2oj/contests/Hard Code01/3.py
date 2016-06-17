def flip(a):
	b = [1-x for x in a]
	return b
n = input()
a = map(int,raw_input().split())

ans = 0
for i in xrange(n):
	for j in xrange(i,n):
		# print "i:",i,"j:",j
		f = 0
		s = 0
		t = 0
		try:
			f = a[:i].count(1)
		except:
			pass
		try:
			# print "flipping"
			x = flip(a[i:j+1])
			s = x.count(1)
		except:
			pass
		try:
			t = a[j+1:].count(1)
		except:
			pass
		# print f,s,t
		ans = max(ans, f+s+t)

print ans