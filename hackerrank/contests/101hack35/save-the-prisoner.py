
def solve(n, m, s):
	m %= n
	Id = s + m
	Id %= n
	return Id

for _ in xrange(input()):
	n, m, s = map(int, raw_input().split())
	ans = solve(n, m, s) - 1
	print ans if ans else ans+n