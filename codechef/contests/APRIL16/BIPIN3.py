MAX = 10**9 + 7
def solve(n, k):
	return (k*pow(k-1,n-1,MAX))%MAX

for _ in xrange(input()):
	print solve(*map(int, raw_input().split()))