### Following is the naive recursive solution

def solve(a, n):
	if n == 0 or n == 1: return n
	temp = []
	for j in xrange(n-1):
		if a[j] < a[n-1]:
			temp.append()


### Following is a O(n^2) solution
def lis(a):
	n = len(a)
	tab = [1]*n
	for i in xrange(1,n):
		for j in xrange(i):
			if a[i] > a[j] and tab[j]+1 > tab[i]:
				tab[i] = tab[j]+1
	return max(tab)

### Below is O(NlogN) solution for longest increasing subsequence

from collections import defaultdict
def lis2(a):
	d = defaultdict(int)
	d[1] = a[0]
	maxyet = d[1]
	minyet = d[1]
	minl = 1
	maxl = 1
	for i in xrange(1,len(a)):
		# if a[i] is least among all the endpoint, start a new endpoint
		if a[i] < minyet:
			d[1] = a[i]
		elif a[i] > d[maxl]:
			d[maxl+1] = a[i]
			maxl += 1
		else:
			for s in sorted(d.keys()):
				if d[s] > a[i]:
					d[s] = a[i]
					break
	return max(d.keys())

a = map(int, raw_input().split(','))
print solve(a, len(a))