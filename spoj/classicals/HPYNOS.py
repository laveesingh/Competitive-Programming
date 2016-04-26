from collections import defaultdict
store = defaultdict(int)
i=0
def solve(n):
	a = str(n)
	s = sum([int(s)**2 for s in a])
	if s == 1:
		return True
	if store[s]:
		return False
	store[s] = 1
	return solve(s)

n = input()
print len(store)+1 if solve(n) else -1

