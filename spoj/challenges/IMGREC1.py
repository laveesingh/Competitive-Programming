def solve(a, h, w):
	for i in xrange(1,h-1):
		for j in xrange(1,w-1):
			if a[i][j] == 'x':
				if a[i-1][j] == 'x' and a[i+1][j] == 'x' and a[i][j-1] == 'x' and a[i][j+1] == 'x':
					return True
				if a[i-1][j-1] == 'x' and a[i-1][j+1] == 'x' and a[i+1][j+1] == 'x' and a[i+1][j-1] == 'x':
					return True
	return False

for _ in xrange(input()):
	raw_input()
	n = input()
	raw_input()
	ans = ""
	for __ in xrange(n):
		h, w = map(int, raw_input().split())
		a = []
		for ___ in xrange(h):
			a.append(raw_input())
		ans += 'x' if solve(a, h, w) else '0'
	print ans