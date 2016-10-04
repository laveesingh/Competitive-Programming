mod = 10**9 + 7
n = input()

a = map(int, raw_input().split())

freq = [0] * n

power = [1]*(n+1)
for i in xrange(1,n+1):
	power[i] = (power[i-1]*2)%mod

freq[0] = power[n] - 1
first = n-2
second = 0
ind = 1
while first >= second:
	freq[ind] = power[first] - power[second]
	ind += 1
	first -= 1
	second += 1

for i in xrange(1, (n+1)/2):
	freq[i] += freq[i-1]

ans = 0

for i in xrange(n):
	if i < (n+1)/2:
		ans = (ans + a[i] * freq[i])%mod
	else:
		ans = (ans + a[i]*freq[n-i-1])%mod

print ans