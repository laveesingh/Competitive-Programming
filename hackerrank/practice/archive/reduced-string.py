'''input
baab
'''

a = list(raw_input())
if len(a) == 1: print a
else:
	flag = 0
	while len(a) > 1 and flag == 0:
		flag = 1
		for i in xrange(0,len(a)-1):
			if a[i] == a[i+1]:
				del a[i]
				del a[i]
				flag = 0
				break
	print ''.join(a) if a else "Empty String"
