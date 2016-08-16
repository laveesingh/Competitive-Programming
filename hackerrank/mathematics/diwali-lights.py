'''input
3
1
2
3
'''

mod = 10**5

f = [0]*(10**4)
f[0] = 1
for i in xrange(1,10**4):
	f[i] = f[i-1]*i

def npr(n, r):
	return (f[n]/f[r])%mod

def solve(n):
	ans = 0
	for i in xrange(1,n+1):
		ans += npr(n,i)
	return ans%mod

for _ in xrange(int(raw_input())):
	print solve(int(raw_input()))