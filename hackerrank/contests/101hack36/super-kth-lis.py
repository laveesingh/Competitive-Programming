
# def comparison(a, b):
# 	for i in xrange(len(a)):
# 		if a[i] < b[i]:
# 			return -1
# 		elif a[i] > b[i]:
# 			return 0
# 	return 0


# arr = None

# def lcs(a, b):
# 	global arr
# 	arr = [[0 for i in xrange(len(b)+1)] for j in xrange(len(a)+1)]
# 	for i in xrange(1,len(a)+1):
# 		for j in xrange(1,len(b)+1):
# 			if a[i-1] == b[j-1]:
# 				arr[i][j] = arr[i-1][j-1] + 1
# 			else:
# 				arr[i][j] = max(arr[i-1][j], arr[i][j-1])
# 	# return arr

# # arr = lcs(a,b) # to be modified

# def lcss(a, b, l1, l2):
# 	global arr
# 	if l1 == 0 or l2 == 0:
# 		return set([()])
# 	if a[l1-1] == b[l2-1]:
# 		Set = lcss(a, b, l1-1, l2-1)
# 		Set1 = set()
# 		for s in Set:
# 			# s.append(a[l1-1])

# 			Set1.add(s+(a[l1-1],))
# 		return Set1
# 	else:
# 		Set = set()
# 		Set1 = set()
# 		if arr[l1-1][l2] >= arr[l1][l2-1]:
# 			Set = lcss(a, b, l1-1, l2)
# 		if arr[l1][l2-1] >= arr[l1-1][l2]:
# 			Set1 = lcss(a, b, l1, l2-1)
# 		for s in Set:
# 			Set1.add(s)
# 		return Set1
		

# def removeDuplicates(a):
# 	f = {}
# 	tod = []
# 	for i,s in enumerate(a):
# 		if f.get(s):
# 			tod.append(i)
# 		else: f[s] = 1
# 	for s in tod[::-1]:
# 		del a[s]
# 	return a



# def solve(a, n):
# 	# print "Solve starts here"
# 	a = removeDuplicates(a)
# 	b = sorted(a)
# 	lcs(a,b)
# 	# print arr
# 	# print "Let's compute all lcss"
# 	Lcss = list(lcss(a, b, len(a), len(b)))
# 	# print Lcss
# 	# print Lcss
# 	if (len(Lcss)) <= n-1:
# 		print -1
# 		return
# 	Lcss.sort(cmp=comparison)
# 	ans = Lcss[n-1]
# 	# print "The answer is: ", ans
# 	for s in ans:
# 		print s,
# 	print

# n, k = map(int, raw_input().split())
# a = map(int, raw_input().split())

# solve(a, k)
# # print removeDuplicates(a)



def lis(a):
	n = len(a)
	tab = [1]*n
	for i in xrange(1,n):
		for j in xrange(i):
			if a[i] > a[j] and tab[j]+1 > tab[i]:
				tab[i] = tab[j]+1
	
	return max(tab)
