
def solve(d, m, r):
	for i in xrange(len(m)):
		if d%m[i] == r[i]:
			return True
	return False

n = input()
m = map(int, raw_input().split())
r = map(int, raw_input().split())

ans = 0

for day in xrange(1000000):
	ans += 1 if solve(day, m, r) else 0
print "0.%d"%ans