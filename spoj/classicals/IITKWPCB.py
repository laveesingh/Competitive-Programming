def solve(n):
	if n%2:
		return n/2
	else:
		ans = n/2 - 1
		return ans if ans%2 else ans -1
for  _ in xrange(input()):
	print solve(input())