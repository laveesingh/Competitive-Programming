
def summ(n):
	return (n*(n+1))/2

def solve(n):
	l3 = n/3
	l5 = n/5
	l15 = n/15
	if not n%3: l3 -= 1
	if not n%5: l5 -= 1
	if not n%15: l15 -= 1
	s1 = 3*summ(l3)
	s2 = 5*summ(l5)
	s3 = 15*summ(l15)
	return s1+s2-s3

for _ in xrange(input()):
	print solve(input())
