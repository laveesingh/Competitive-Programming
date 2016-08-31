'''input
1
2
1 1
'''

def solve(a):
	a.insert(0,1)
	print "initial a:",a
	n =len(a)
	if n%2: i = n-3
	else: i = n-2
	a[i] -= 1
	if a[i] == 0:
		if i > 0:
			a[i-1] += 1
		else:
			print "ie:",a, 
			a[0] = 1
			a.insert(0, 1)
			print " => ",a
			i += 1
		if i < n-2:
			a[i+1] += 1
			del a[i+2]
		else:
			a[i+1] -= 1
		# if a[i+1] == 1:
		# 	a[i] += 1
		# 	del a[i+1]
		# else:
		# 	a[i+1] -= 1
		# 	a[i] += 1
	else:
		if a[i+1] > 1:
			a[i+1] -= 1
			a.insert(i+1, 1)
			a.insert(i+1, 1)
		else:
			if i < n-2:
				a[i+2] += 1
			else:
				a.append(1)
	return a[1:]

for _ in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	ans = solve(a)
	print len(ans)
	for s in ans: print s,
	print