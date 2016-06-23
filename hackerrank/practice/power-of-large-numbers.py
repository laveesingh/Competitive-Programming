m = 10**9+7

for _ in xrange(input()):
	a, b = map(int,raw_input().split())
	print pow(a%m, b%(m-1), m)
