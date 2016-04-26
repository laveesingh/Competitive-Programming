INF = 10**10
n = input()
k = input()
a = []
for _ in xrange(n):
	a.append(input())
a.sort()
def solve(n, k):
	cof = [0 for i in xrange(n)]
	# cof[] = csum = a[1]-a[0]
	cof[0] = 0
	# cof[2] = a[1]-a[0]
	S  = [0 for i in xrange(n)]
	S[0] = a[0]
	for i in xrange(1,k):
		cof[i] = cof[i-1] + a[i]*i - S[i-1]
		S[i] = S[i-1]+a[i]
	csum = sum(a[i] for i in xrange(1,k))
	j = 1
	# k = 0
	# print cof
	for i in xrange(k,n):
		# print 'csum:',csum
		cof[i] = cof[i-1] + (k-1)*a[j-1] - csum
		cof[i] += (k-1)*a[i] - csum
		csum -= a[j]
		csum += a[i]
		j += 1

	# print a
	# print cof
	return min(cof[k-1:])

	# print cof
	# print S
	# return ans


print solve(n, k)