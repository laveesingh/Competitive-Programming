from pprint import pprint
ans = 0

# dict[tuple] = (divided tuple of list), value

def isPos(a, n):
	s = 0
	s2 = sum(a)
	for i in xrange(len(a)-1):
		s += a[i]
		s2 -= a[i]
		if s == s2 and i != len(a)-1:
			return (a[:i+1],a[i+1:], n+1)
	return False

store = {}

def solve(a, n):
	x = isPos(a, n)
	if x:
		store[tuple(a)] = x
		a1 = x[0]
		a2 = x[1]
		solve(a1, n+1)
		solve(a2, n+1)

for _ in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	store = {}
	solve(a, 0)
	ans = 0
	for s in store:
			if store[s][2] > ans:
				ans = store[s][2]
	print ans

# def case():
# 	n = random.randint(1,9)
# 	print n
# 	for _ in xrange(n):
# 		l = random.randint(1,20)
# 		a = [random.randint(1,8) for i in xrange(l)]
# 		print l
# 		for s in a: print s,
# 		print