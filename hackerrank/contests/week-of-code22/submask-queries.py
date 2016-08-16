'''input
3 4
1 3 110
3 100
2 1 011
3 010
'''

from itertools import combinations
from collections import defaultdict

def subsets(a):
	n = len(a)
	subs = []
	inds = [i for i in xrange(n) if a[i]=='1']
	for i in xrange(len(inds)+1): # maybe I've to start this loop from 1 instead of 0
		for s in combinations(inds, i):
			st = ['0']*n
			for x in s:
				st[x] = '1'
			subs.append(''.join(st))
	return subs

n, m = map(int, raw_input().split())
store = defaultdict(int)

for _ in xrange(m):
	query = raw_input().split()
	if len(query) == 3:
		t, x, s = query
		t = int(t)
		x = int(x)
		subs = subsets(s)
		if t == 1:
			for subset in subs:
				store[subset] = x
		else:
			for subset in subs:
				store[subset] = store[subset]^x


	else:
		print store[query[1]]