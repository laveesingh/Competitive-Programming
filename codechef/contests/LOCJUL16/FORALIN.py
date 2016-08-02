n = int(raw_input())

a = raw_input().split()

deleted = [0]*n
a.sort()
for i in xrange(n-1):
	if len(a[i]) >= 2 and a[i][-2:] == "ka":
		for j in xrange(i+1,n):
			if len(a[j]) >= 2 and a[j][-2:] == "ki" and a[i]
