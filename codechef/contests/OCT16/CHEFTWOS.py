
def good(a):
	n = len(a)
	visited = [0]*(n+1)
	c = 0
	i = 0
	ans = 1
	while 1:
		visited[i] = 1
		c += 1
		if i == n-1:
			break
		if a[i] == '1':
			if i > 0 and not visited[i-1]: i -= 1
			elif i < n-1 and not visited[i+1]: i += 1
			else:
				ans = 0
				break
		else:
			if i > 1 and not visited[i-2]: i -= 2
			elif i < n-2 and not visited[i+2]: i += 2
			else:
				ans = 0
				break
	if c != n:
		ans = 0
	return ans

def Map(n, m):
	bn = bin(n)[2:].zfill(m)
	inds = []
	for i in xrange(len(bn)):
		if bn[i] == '1':
			inds.append(i)
	return inds

def solve(a, b):
	ans = 0
	for i in xrange(2**len(a)):
		inds = Map(i, len(a))
		c = a[:]
		d = b[:]
		#print "inds:",inds
		for s in inds:
			c[s], d[s] = d[s], c[s]
		c = ''.join(c)
		d = ''.join(d)
		if good(c) and good(d):
			ans += 1
	return ans
t = input()
for _ in xrange(t):
	a = list(raw_input())
	b = list(raw_input())
	print solve(a,b)
