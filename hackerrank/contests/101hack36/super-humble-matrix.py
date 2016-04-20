from itertools import permutations

def ishumble(a, n, m):
	for i in xrange(n):
		for j in xrange(m):
			if (i>0 and a[i][j] < a[i-1][j]) or (i > 0 and j > 0 and a[i][j] < a[i-1][j-1])  or (j > 0 and a[i][j] < a[i][j-1]): return False
	return True

def solve(n, m):
	a = range(1,n*m+1)
	ans = 0
	for s in permutations(a):
		s  = list(s)
		cur = [[s[i] for i in xrange(j,j+m)] for j in xrange(0,len(s),m)]
		if ishumble(cur, n,m):
			print "humble:",cur
			ans += 1
	print ans

solve(*map(int, raw_input().split()))