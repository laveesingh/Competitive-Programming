
# def solve(a, n, k):
# 	a.sort()
# 	freq = {}
# 	for i in xrange(n-1):
# 		diff = []
# 		for j in xrange(i+1,n):
# 			diff.append(a[j]-a[i])
# 		freq[i] = diff
# 	print "created the difference table."
# 	m = 10**10
# 	for i in xrange(k,n):
# 		print '.',
# 		# print "i:",i
# 		temp = 0
# 		for j in xrange(i-1,i-k-1,-1):
# 			# print "j:",j,"freq[][]:",freq[j][:i-j-1]
# 			try:
# 				temp += sum(freq[j][:i-j-1])
# 			except: continue
			
# 		if temp < m:
# 			m = temp

# 	return m

# n = input()
# k = input()
# a = []
# for _ in xrange(n):
# 	a.append(input())
# print solve(a, n, k)




# def solve(a, n, k):
# 	a.sort()
# 	cur = 0
# 	for i in xrange(k):
# 		for j in xrange(i+1,k):
# 			cur += a[j]-a[i]
# 	m = cur
# 	print "current minimum is:",m
# 	for i in xrange(n-k):
# 		temp = a[i+k]
# 		print "i:",i,"temp:",temp
# 		for j in xrange(i+1,i+k):
# 			print "cur:",cur,
# 			cur -= a[j]-a[i]
# 			cur += temp-a[j]
# 			#cur += temp - 2*a[j] + a[i]
# 		print
# 		if cur < m:
# 			m = cur
# 	return m

# n = input()
# k = input()
# a = []
# for _ in xrange(n):
# 	a.append(input())
# print solve(a, n, k)

def solve(a, n, k):
	a.sort()
	cur_diff = 0
	for i in xrange(k-1):
		cur_diff += a[i+1]-a[i]
	min_diff = cur_diff
	mini = 0
	for i in xrange(n-k):
		cur_diff -= a[i+1]-a[i]
		cur_diff += a[i+k]-a[i+k-1]
		if cur_diff < min_diff:
			min_diff = cur_diff
			mini = i
	f = 0
	# print "mini:",mini
	i = mini
	for j in xrange(i,i+k-1):
		for l in xrange(j+1,i+k):
			f += a[l]-a[j]
	return f

n = input()
k = input()
a = []
for _ in xrange(n):
	a.append(input())
print solve(a, n, k)