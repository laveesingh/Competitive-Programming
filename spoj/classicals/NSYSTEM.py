def tomcxi(n):
	ret = ""
	i = n%10
	if i==1:	ret = "i" + ret
	elif i > 1: ret = str(i) + "i" + ret
	x = (n%100)/10
	if x == 1:  ret = "x" + ret
	elif x > 1: ret = str(x) + "x" + ret
	c = (n%1000) / 100
	if c == 1: ret = "c" + ret
	elif c > 1: ret = str(c) + "c" + ret
	m = n/1000
	if m == 1: ret = "m" + ret
	elif m > 1: ret = str(m) + "m" + ret
	return ret

def todec(a):
	n = 0
	i = 0 
#	print 'a:',a
	while i < len(a):
		ind = len(a)-i-1
#		print 'i:',i,'ind:',ind
		if a[ind] == 'i':
			if ind > 0 and a[ind-1].isdigit(): 
				n += int(a[ind-1])
				i += 2
			else: 
				n += 1
				i += 1
		elif a[ind] == 'x':
			if ind > 0 and a[ind-1].isdigit(): 
				n += int(a[ind-1])*10
				i += 2
			else: 
				n += 10
				i += 1
		elif a[ind] == 'c':
			if ind > 0 and a[ind-1].isdigit(): 
				n += int(a[ind-1])*100
				i += 2
			else: 
				n += 100
				i += 1
		elif a[ind] == 'm':
			if ind > 0 and a[ind-1].isdigit(): 
				n += int(a[ind-1])*1000
				i += 2
			else: 
				n += 1000
				i += 1
	return n

for _ in xrange(int(raw_input())):
	a, b = raw_input().split()
	na = todec(a)
	nb = todec(b)
	nc = na + nb
	print tomcxi(nc)
