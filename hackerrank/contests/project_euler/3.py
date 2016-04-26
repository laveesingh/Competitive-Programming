
def primeF(n):
	a = []
	if not n%2:
		a.append(2)
		while not n%2:
			n /= 2
	b = 3
	if n == 1: return a
	while b * b <= n:
		if not n%b:
			a.append(b)
			while not n%b:
				n /= b
		b += 2
	a.append(n)
	return max(a)


for _ in xrange(input()):
	print primeF(input())