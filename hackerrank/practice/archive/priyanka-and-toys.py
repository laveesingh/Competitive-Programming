
def solve(a):
	a.sort()
	ans = 1
	cur = a[0]
	for s in a[1:]:
		if s <= cur + 4:
			continue
		else:
			ans += 1
			cur = s
	return ans

n = int(raw_input())
print solve(map(int, raw_input().split()))
