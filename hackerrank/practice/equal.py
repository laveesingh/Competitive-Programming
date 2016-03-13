

def diff(a, n):
	ans = 0
	n -= a
	ans += n/5
	n %= 5
	if n:
		ans += n/2
		n %= 2
		ans += n
	return ans


def solve(a):
	
	ans = 0
	if (1 in a) and (5 in a or 10 in a):
		for i in xrange(len(a)):
			if a[i]== 1:
				ans += 1
				a[i] = 0

	if (2 in a) and (5 in a or 10 in a):
		for i in xrange(len(a)):
			if a[i]== 2:
				ans += 1
				a[i] = 0

	mini = min(a)
	for s in a:
		ans += diff(mini, s)
	return ans

def solve2(a):
	
	ans = 0
	mini = min(a)
	for s in a:
		ans += diff(mini, s)
	return ans

for _ in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	print min(solve(a), solve2(a))