from itertools import combinations

def solve(m, n):
	acts = []
	for i in xrange(n):
		acts.append(tuple(map(int, raw_input().split())))

	begs = []
	ends = []
	mids = []
	for s in acts:
		if s[0] == 0:
			begs.append(s)
		if s[-1] == m:
			ends.append(s)
		if s[0] != 0 and s[-1] != m:
			mids.append(s)


