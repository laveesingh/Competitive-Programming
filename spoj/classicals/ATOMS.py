
from math import floor, log

def solve(n, k, m):
	m = float(m)
	x = int(log(m/n, k)) 
	return x if x > 0 else 0

for  _ in xrange(input()):
	print solve(*map(int, raw_input().split()))


def solve(n):
 for i in xrange(1,n/2):
  for j in xrange(1,100):
   if (j+1)*i+(j*(j+1))/2 == n:
    print i,j
