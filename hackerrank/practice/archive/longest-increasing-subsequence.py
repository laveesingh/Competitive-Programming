# from collections import defaultdict

# def ceilindex(a, l, r, key):
# 	while r-l > 1:
# 		m = l+(r-l)/2
# 		if a[m]>=key: r = m
# 		else: l = m
# 	return r


# def lis2(a):
# 	d = [0]*n
# 	d[0] = a[0]
# 	minl = 1
# 	maxl = 1
# 	for i in xrange(1,len(a)):
# 		# if a[i] is least among all the endpoint, start a new endpoint
# 		if a[i] < d[0]:
# 			d[0] = a[i]
# 		elif a[i] > d[maxl-1]:
# 			d[maxl] = a[i]
# 			maxl += 1
# 		else:
# 			d[ceilindex(d, -1, maxl-1, a[i])] = a[i]
			
# 	return maxl

# n = input()
# a = []
# for i in xrange(n):
# 	a.append(input())

# print lis2(a)

def solve(a):
	b = [0]*len(a)
	b[0] = 1
	for i in xrange(1,len(a)):
		for j in xrange(i+1):
			if a[i] > a[j]:
				b[i] = max(b[i],1+b[j])
	return max(b)

n = input()
a = []
for i in xrange(n):
	a.append(input())

print solve(a)