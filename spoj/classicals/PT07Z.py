from collections import defaultdict

tree = defaultdict(list)
depths = defaultdict(list)

def set_depths(node=1):
	if (depths[node]): return
	if len(children(node)) == 0:
		depths[node].append(0)
	else:
		for s in children(node):
			set_depths(s)
			depths[node].append(max(depths[s])+1)


def children(node):
	if tree.get(node):
		return tree[node]
	return []

t = int(raw_input())
for _ in xrange(t-1):
	u, v = map(int, raw_input().split())
	tree[u].append(v)

set_depths()
def max_sum(a):
	if len(a) < 3:
		return sum(a)
	a.sort()
	return a[-1]+a[-2]

mpath = 0

for i in xrange(t):
	x = max_sum(depths[i])
	if x > mpath:
		mpath = x
print mpath