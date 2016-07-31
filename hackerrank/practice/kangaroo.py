
def solve(x1, x2, v1, v2):
	if v1 <= v2:
		return False
	t = float(x1-x2)/float(v2-v1)
	if t-int(t) == 0 and t > 0:
		return True
	return False

x1, v1, x2, v2 = map(int,raw_input().split())

print solve(x1, x2, v1, v2)