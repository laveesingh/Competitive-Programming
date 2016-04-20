def solve(a):
	cs, ms = 0, a[0]
	i = 0
	while i < len(a):
		cs += a[i]
		if cs > ms: ms = cs
		if cs < 0:
			cs = 0
		i += 1
	i, ii = 0
	ans = 0
	cs = 0
	add = 1
	while i < len(a):
		cs += a[i]
		if cs == ms:
			ans += add
		fakecs = cs
		if cs > ms and a[ii] > 0:
			while 



print solve(map(int, raw_input().split()))