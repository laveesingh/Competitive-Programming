from collections import defaultdict
store = defaultdict(int)
def solve(a, m, n):
	if n == 0:
		return 1
	if n < 0:
		return 0
	if m <= 0 and n >= 1:
		return 0
	x = store[(m-1,n)] if store[(m-1,n)] else solve(a[:-1],m-1,n)
	store[(m-1,n)] = x
	y = store[(m,n-a[m-1])] if store[(m,n-a[m-1])] else solve(a,m,n-a[m-1])
	store[(m,n-a[m-1])] = y
	return x + y
	# return solve(a[:-1],m-1,n)+solve(a,m,n-a[m-1])

n, m  = map(int, raw_input().split())
a = map(int, raw_input().split())
print solve(a,m,n)