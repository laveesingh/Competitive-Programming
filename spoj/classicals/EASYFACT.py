from math import factorial as f

def solve(n):
	ans = 0
	for i in xrange(1,n/2):
		for j in xrange(1,10000):
			if (j+1)*i+(j*(j+1))/2 == n:
				ans += 1
	return ans

for _ in xrange(input()):
	#n, m = map(int, raw_input().split())
	n=input()
	print solve(f(n))
    