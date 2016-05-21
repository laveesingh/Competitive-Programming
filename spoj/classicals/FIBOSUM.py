MOD = 10**9 + 7
sq = 5**0.5
phi = (1+sq)/2
nphi = 1-phi

def fib(n):
	return int((phi ** n - nphi ** n)/sq)

def fibosum(n):
	return fib(n+1)-1

t = input()
for _ in range(int(t)):
	n, m = map(int, input().split())
	fibn = fib(n)
	fibn1 = fib(n+1)
	x = 1+fibosum(m-n)
	y = fibosum(m-n+1)
	print (x*fibn + y*fibn1)%MOD