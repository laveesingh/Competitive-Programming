def solve(a):
	if len(a) <= 3:
		return sum(a)

	else:
		ans = max(
			a[0]+max(solve(a[2:]),solve(a[3:]),solve(a[4:])),
			a[1]+max(solve(a[5:]),solve(a[3:]),solve(a[4:])),
			a[2]+max(solve(a[5:]),solve(a[6:]),solve(a[4:]))
			)
		return ans

for _ in xrange(input()):
	n = input()
	print solve(map(int, raw_input().split()))