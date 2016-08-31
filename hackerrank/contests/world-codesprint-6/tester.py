'''input
4
12 8 3
10 3 3
9 10 2
9 10 2
'''

from itertools import combinations as comb

sigma = lambda n: (n*(n+1))/2

def solve(n, k, b):
	if b == 1:
		if n <= k:
			return [n]
		return [-1]
	if sigma(b) > n:
		return [-1]
	if sigma(k)-sigma(k-b-1) < n:
		return [-1]

	lo = 1
	hi = 10 ** 20
	x = 1
	while (lo <= hi):
		if x == (lo+hi)/2:
			break
		x = (lo+hi)/2
		csum = sigma(x+b-1)-sigma(x-1)
		# print "x:",x,"csum:",csum
		if csum < n:
			lo = x
		else:
			hi = x-1
	portion = range(x,x+b)
	if portion[-1] > k:
		return [-1]
	csum = sigma(x+b-1)-sigma(x-1)
	if csum == n:
		return portion
	if csum > n:
		return [-1]
	if portion[-1] >= k:
		return [-1]
	diff = n-csum
	# for i in xrange(len(portion)-diff, len(portion)):
	# 	portion[i] += 1
	portion[-diff] = portion[-1]+1
	return portion

def brute(n, k, b):
	avail = range(1,k+1)
	for seq in comb(avail, b):
		seq = list(seq)
		# print "seq:",seq
		if sum(seq) == n:
			return 1
	return -1

for _ in xrange(input()):
	n, k, b = map(int, raw_input().split())
	ans = solve(n, k, b)
	if len(ans) != len(set(ans)):
		print "Duplicate"
		break
	if ans[-1] > k:
		print n,k,b
		print "Out of Bound"
		break
	if sum(ans) == n:
		print n,"True"
	else:
		if sum(ans) == -1:
			if brute(n, k, b) == 1:
				print "-1 False"
				break
			else:
				print -1,"True"
		else:
			print sum(ans),"False"
			break