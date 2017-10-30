
def solve(a):
	i = 1
	# count inversions in the array
	inv = 0
	f = {}
	f[a[-1]] = 0
	for i in xrange(len(a)-2,-1,-1):
		for j in xrange(i+1,len(a)):
			if a[j] == a[i]-1:
				f[a[i]] = f[a[j]] + 1
				inv += f[a[i]]
				print f
				break
			else:
				f[a[i]] = 0
	return not inv%2

for _ in xrange(int(raw_input())):
	n = raw_input()
	a = map(int,raw_input().split())
	print "YES" if solve(a) else "NO"
			