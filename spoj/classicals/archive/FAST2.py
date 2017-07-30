mod = 1298074214633706835075030044377087
def solve(n):
	return pow(2,n+1,mod)-1

for _ in xrange(int(raw_input())):
	n = int(raw_input())
	print solve(n)