n, k = map(int, raw_input().split())
a = map(int, raw_input().split())

total = 0

for i in xrange(len(a)-1):
	for j in xrange(i+1, len(a)):
		if (a[i]+a[j]) % k == 0:
			total += 1
print total