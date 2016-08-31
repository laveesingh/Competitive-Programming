'''input
4 3
1 7 2 4
'''

I = lambda : map(int, raw_input().split())

n,k = I()
a = I()
freq = [0]*k
for i in xrange(n):
	freq[a[i]%k] += 1

ans = 0
ans += freq[0]>0
if k%2 == 0:
	ans += freq[k/2]>0

for i in xrange(1,(k+1)/2):
	if k%2 or i != k/2:
		ans += max(freq[i], freq[k-i])

print ans