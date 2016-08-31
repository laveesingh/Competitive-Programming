mod = 10**9 + 7
def solve(n):
	return pow(n, (pow(2,n,mod-1) - n%(mod-1)) , mod)

for _ in xrange(input()):
	n = input()
	print solve(n) if n != 1 else 2