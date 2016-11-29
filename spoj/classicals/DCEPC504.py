import sys
sys.setrecursionlimit(10**6)
def solve(n, k):
#	print 'finding ',n,'th gens ',k,'th child'
	if n == 1: return 1
	if n == 2: return k%2
	if k <= (1<<(n-2)): return solve(n-1, k)
	return 1^solve(n-1, k - (1<<n-2))

for _ in xrange(int(raw_input())):
	n, k = map(int, raw_input().split())
	print 'Male' if solve(n, k) else 'Female'
