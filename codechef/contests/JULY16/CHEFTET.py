I = lambda : map(int,raw_input().split())
def solve(a, b, x):
	n = len(a)
	for i in xrange(n):
		if a[i] == x: continue
		if a[i] != x:
			a[i] += b[i-1] if i > 0 else 0
			if i > 0: b[i-1] = 0
		if a[i] != x:
			if a[i]+b[i] == x:
				a[i] += b[i]
				b[i] = 0
				continue
			if i < n-1 and a[i] + b[i+1] == x:
				a[i] += b[i+1]
				b[i+1] = 0
				continue
			else:
				a[i] += b[i]
				b[i] = 0
				if i < n-1 and a[i] != x:
					a[i] += b[i+1]
					b[i+1] = 0
	# print "final a: ", a
	# print "final b: ", b
	aset = set(a)
	if len(aset) == 1:
		if not any(b):
			return True
	return False
	


for _ in xrange(input()):
	n = input()
	b = I()
	a = I()
	if n == 1:
		print a[0]+b[0]
		continue
	# f = [a[0]+b[0], a[0]+b[1], a[0]]
	# s = [solve(list(a), list(b), i) for i in f]
	# t = []
	# for i in xrange(3):
	# 	if s[i]:
	# 		t.append(f[i])
	# # print f, s, t
	# if not t:
	# 	print -1
	# else:
	# 	print max(t)
	x = (sum(a)+sum(b))/n
	if solve(list(a), list(b), x):
		print x
	else:
		print -1