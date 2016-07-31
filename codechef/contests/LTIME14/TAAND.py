

n = input()
a = []
for _ in xrange(n):
	a.append(int(raw_input()))

ans = 0
for i in xrange(len(a)-1):
	for j in xrange(i+1, len(a)):
		ans = max(ans, a[i]&a[j])
print ans