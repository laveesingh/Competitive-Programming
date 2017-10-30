I = lambda : map(int, raw_input().split())

n, k = I()

a = I()
count = 0
for i in xrange(len(a)):
	for j in xrange(i+1, len(a)):
		if (a[i]+a[j])%k == 0:
			count += 1

print count