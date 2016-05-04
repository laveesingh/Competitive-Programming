import sys
INF = sys.maxint
def solve(a, i, j):
	if i == j: return 0
	minm = INF
	for k in xrange(i,j):
		minm = min(solve(a,i, k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j], minm)
	return minm


a = map(int, raw_input().split())
print solve(a, 1, len(a)-1)