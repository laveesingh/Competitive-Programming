from fractions import gcd


def lcm(a, b):
	return (a*b) / gcd(a,b)

def good(x):
	while( x%2 == 0): x /= 2
	while (x%3 == 0): x /= 3
	return x == 1

n = int(raw_input())
a =map(int, raw_input().split())

ans = "YES"
L = 1
for i in xrange(len(a)):
	L = lcm(L, a[i])

for i in xrange(n):
	cur = L / a[i]
	if not good(cur):
		ans = "NO"
		break
print ans
