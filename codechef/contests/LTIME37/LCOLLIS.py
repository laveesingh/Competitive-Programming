t = input()

for _ in xrange(t):
	n, m = map(int, raw_input().split())
	ans = 0
	a = []
	for i in xrange(n):
		a.append(raw_input())
	a = zip(*a)
	# print a
	for s in a:
		x = s.count('1')
		ans += (x*(x-1))/2
	print ans
