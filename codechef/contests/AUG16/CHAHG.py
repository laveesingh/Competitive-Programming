'''input
3
3
0 1
2 2
0 3
2
2 1
1 2
3
1 1
2 2
3 3
'''


from math import ceil, floor
import sys

inf = sys.maxint

def isL(a):
	n = len(a)
	for i in xrange(n):
		if i%2:
			if i < n-1 and a[i] <= a[i+1]: return 0
			if a[i] <= a[i-1]: return 0
		else:
			if i > 0 and a[i] >= a[i-1]: return 0
			if i < n-1 and a[i] >= a[i+1]: return 0
	return 1

def isG(a):
	n = len(a)
	for i in xrange(n):
		if i%2:
			if i < n-1 and a[i] >= a[i+1]: return 0
			if a[i] >= a[i-1]: return 0
		else:
			if i > 0 and a[i] <= a[i-1]: return 0
			if i < n-1 and a[i] <= a[i+1]: return 0
	return 1

def ttgt(a, b, ra, rb):
	''' a < b: time for a to be greater than b'''
	if a > b: return 0
	if ra <= rb: return inf
	t = float(a - b)/float(rb - ra)
	# t = round(t, 3)
	if t%1:
		return int(ceil(t))
	return int(floor(t)+1)

def ttge(a, b, ra, rb):
	''' a < b: time for a to be greater than or equal to b'''
	if a >= b: return 0
	if ra <= rb: return inf
	t = float(a - b)/float(rb - ra)
	# t = round(t,3)
	return int(ceil(t))

def solve():
	n = int(raw_input())
	H = []
	M = []
	ans = []
	for i in xrange(n):
		x, y = map(int, raw_input().split())
		H.append(x)
		M.append(y)

	if n == 1:
		ans.append((0,"Inf"))
		return ans

	if isL(H):
		t = inf
		for i in xrange(0,n,2):
			if i > 0:
				t = min(t, ttge(H[i], H[i-1], M[i], M[i-1]))
			if i < n-1:
				t = min(t, ttge(H[i], H[i+1], M[i], M[i+1]))
		if t == inf:
			ans.append((0,"Inf"))
			return ans
		ans.append((0,t-1))
		t = 0
		for i in xrange(0,n,2):
			if i > 0:
				t = max(t, ttgt(H[i], H[i-1], M[i], M[i-1]))
			if i < n-1:
				t = max(t, ttgt(H[i], H[i+1], M[i], M[i+1]))
		if t != inf:
			newH = [H[i]+M[i]*t for i in xrange(n)]
			if isG(newH):
				ans.append((t, "Inf"))
		return ans

	if isG(H):
		t = inf
		for i in xrange(1,n,2):
			t = min(t, ttge(H[i], H[i-1], M[i], M[i-1]))
			if i < n-1:
				t = min(t, ttge(H[i], H[i+1], M[i], M[i+1]))
		if t == inf:
			ans.append((0,"Inf"))
			return ans
		ans.append((0,t-1))
		t = 0
		for i in xrange(1,n,2):
			t = max(t, ttgt(H[i], H[i-1], M[i], M[i-1]))
			if i < n-1:
				t = max(t, ttgt(H[i], H[i+1], M[i], M[i+1]))
		
		if t != inf:
			newH = [H[i]+M[i]*t for i in xrange(n)]
			if isL(newH):
				ans.append((t, "Inf"))
		return ans

	t = 0
	# Last odd that goes greater
	for i in xrange(1,n,2):
		t = max(t, ttgt(H[i], H[i-1], M[i], M[i-1]))
		if i < n-1:
			t = max(t, ttgt(H[i], H[i+1], M[i], M[i+1]))
	newH = [H[i]+M[i]*t for i in xrange(n)]
	if isL(newH):
		t2 = inf
		for i in xrange(0,n,2):
			if i > 0:
				t2 = min(t2, ttge(newH[i], newH[i-1], M[i], M[i-1]))
			if i < n-1:
				t2 = min(t2, ttge(newH[i], newH[i+1], M[i], M[i+1]))
		if t2 == inf:
			ans.append((t, "Inf"))
		else:
			ans.append((t,t2-1))
		return ans

	t = 0
	# Last even that goes greater
	for i in xrange(0,n,2):
		if i > 0:
			t = max(t, ttgt(H[i], H[i-1], M[i], M[i-1]))
		if i < n-1:
			t = max(t, ttgt(H[i], H[i+1], M[i], M[i+1]))
	newH = [H[i]+M[i]*t for i in xrange(n)]
	if isG(newH):
		t2 = inf
		for i in xrange(1,n,2):
			t2 = min(t2, ttge(newH[i], newH[i-1], M[i], M[i-1]))
			if i < n-1:
				t2 = min(t2, ttge(newH[i], newH[i+1], M[i], M[i+1]))
		if t2 == inf:
			ans.append((t, "Inf"))
		else:
			ans.append((t, t2-1))
		return ans
	return ans


t = int(raw_input())

for _ in xrange(t):
	ans = solve()
	if len(ans):
		if len(ans) == 2 and ans[0][1]+1 == ans[1][0]:# and False:
			print 1
			print ans[0][0],ans[1][1]
		else:
			print len(ans)
			for s in ans:
				print s[0],s[1]
	else:
		print 0