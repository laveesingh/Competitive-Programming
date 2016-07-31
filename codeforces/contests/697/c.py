from collections import defaultdict

weights = defaultdict(int)

def update(u, v, w):
	up = []
	while u > 0:
		up.append(u)
		u /= 2
	vp = []
	lca = 1
	while v > 0:
		vp.append(v)
		if v in up:
			lca = v
			break
		v /= 2
	up = up[:up.index(lca)+1]
	for i in xrange(len(up)-1):
		weights[(up[i],up[i+1])] += w
		weights[(up[i+1],up[i])] += w
	for i in xrange(len(vp)-1):
		weights[(vp[i], vp[i+1])] += w
		weights[(vp[i+1], vp[i])] += w

def Query(u, v):
	ans = 0
	up = []
	while u > 0:
		up.append(u)
		u /= 2
	vp = []
	lca = 1
	while v > 0:
		vp.append(v)
		if v in up:
			lca = v
			break
		v /= 2
	up = up[:up.index(lca)+1]
	for i in xrange(len(up)-1):
		ans += weights[(up[i],up[i+1])]
	for i in xrange(len(vp)-1):
		ans += weights[(vp[i],vp[i+1])]
	print ans


q = int(raw_input())

for _ in xrange(q):
	query = map(int, raw_input().split())
	if query[0] == 1:
		update(*query[1:])
	else:
		Query(*query[1:])
