
# a = None
# dstring = None
# n = None

# def solvef(i, j, x, fi, fj):
# 	global a, dstring, n
# 	if len(x) == 2*n:
# 		dstring.add(x)
# 		return
# 	elif j == n-1:
# 		while len(x) < 2*n and j >=0:
# 			x += a[i^1][j]
# 			j -= 1
# 		if len(x) == 2*n:
# 			dstring.add(x)
# 		return
# 	else:
# 		solvef(i, j+1, x+a[i][j+1], fi, fj)
# 		# if (fj%2)==(j%2) and (fj != j or fi == i):
# 		if (fj%2) != (j%2):
# 			solvef(i^1, j, x+a[i^1][j], fi, fj)
# 		return


# def solveb(i, j, x, fi, fj):
# 	global a, dstring, n
# 	if len(x) == 2*n:
# 		dstring.add(x)
# 		return
# 	elif j == 0:
# 		while len(x) < 2*n and j < n:
# 			x += a[i^1][j]
# 			j += 1
# 		if len(x) == 2*n:
# 			dstring.add(x)
# 		return
# 	else:
# 		solveb(i, j-1, x+a[i][j-1], fi, fj)
# 		# if (fj%2) == (j%2) and (fj != j or fi == i):
# 		if ((fj%2) != (j%2)):
# 			solveb(i^1, j, x+a[i^1][j], fi, fj)
# 		return


# def solve():
# 	global a, dstring, n
# 	dstring = set()
# 	for j in xrange(n):
# 		for i in xrange(2):
# 			if j == 0:
# 				solvef(i, j, a[i][j], i, j)
# 			elif j == n-1:
# 				solveb(i, j, a[i][j], i, j)
# 			else:
# 				# print i, i^1	
# 				temp = a[i][0:j+1][::-1]
# 				temp += a[i^1][0:j+1]
# 				solvef(i^1, j+1, temp+a[i^1][j+1], i^1, j+1)
# 				temp = a[i][j:n]
# 				temp += a[i^1][j:n][::-1]
# 				solveb(i^1, j-1, temp+a[i^1][j-1], i^1, j-1)
# 	print dstring
# 	print len(dstring)

# for _ in xrange(int(input())):
# 	n = int(input())
# 	a = []
# 	a.append(raw_input())
# 	a.append(raw_input())
# 	solve()


a = None

for _ in xrange(input()):
	st = []
	n = input()
	a = []
	a.append(raw_input())
	a.append(raw_input())
	temp = set()
	temp.add(a[0][0]+a[1][0])
	temp.add(a[1][0]+a[0][0])
	st.append(temp)
	# print temp
	for j in xrange(1,n):
		temp = set()
		popped = st[j-1]
		x = a[0][j]
		y = a[1][j]
		for s in popped:
			if s.endswith(a[1][j-1]) and s.startswith(a[0][j-1]):
				temp.add(x+s+y)
				temp.add(s+y+x)
				temp.add(y+x+s)

				for i in xrange(len(s)):
					# if(i == len(s)-1):
					# 	temp.add(y+x+s)
					# else:
						temp.add(s[i:]+y+x+s[:i])
			elif s.endswith(a[0][j-1]) and s.startswith(a[1][j-1]):
				# print s, ' starts with ', a[1][j-1], 'and ends with', a[0][j-1]
				temp.add(x+y+s)
				temp.add(y+s+x)
				temp.add(s+x+y)
				for i in xrange(len(s)):
					# if i == len(s)-1:
					# 	temp.add(x+y+s)
					# else:
						temp.add(s[i:]+x+y+s[:i])
			elif s.endswith(a[0][j-1]):
				temp.add(s+x+y)
			elif s.endswith(a[1][j-1]):
				temp.add(s+y+x)
			elif s.startswith(a[0][j-1]):
				temp.add(y+x+s)
			elif s.startswith(a[1][j-1]):
				temp.add(x+y+s)
		# print len(temp), temp
		st.append(temp)
	print len(st[n-1])


