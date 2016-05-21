from collections import defaultdict
d = defaultdict(int)

def permute(a):
	global d
	new = [0]*len(a)
	for i,s in enumerate(a):
		new[d[i+1]-1] = s
	return new

n, m = map(int,raw_input().split())
p = map(int,raw_input().split())

for i, s in enumerate(p):
	d[s] = i+1

a = range(1,m+n+2)

for i in xrange(m):
	a[i:i+n] = permute(a[i:i+n])
	# print a
print a[m-1]