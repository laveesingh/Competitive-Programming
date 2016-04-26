def ham(a,b):
	ans = 0
	for i in xrange(len(a)):
		if a[i] != b[i]:
			ans += 1
	return ans


def solve(a, k, s):
	if a != 1:
		raise NotImplementedError("Something is wrong.")
	if len(s) >= 3:
		return 0
	else:
		if len(s) == 1:
			if s == "a":
				if k == 0: return 1
				else: return 0
			else:
				if k <= 1: return 1
				else: return 0
		if len(s) == 2:
			if ham("aa", s)<=k:
				return 1
			else: return 0


for _ in xrange(input()):
	a, k = map(int, raw_input().split())
	s  = raw_input()
	print solve(a, k, s)