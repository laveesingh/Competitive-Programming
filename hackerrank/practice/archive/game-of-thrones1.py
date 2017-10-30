from collections import defaultdict
def solve(a):
	dd = defaultdict(int)
	for s in a:
		dd[s] += 1
	ans = 0
	for s in dd:
		if dd[s]%2:
			ans += 1
		if ans > 1:
			return False
	return True

a = raw_input()
print "YES" if solve(a) else "NO"