import sys
from collections import defaultdict

def comp(a,b):
	if a[1] == b[1]:
		if a[0] < b[0]:
			return 0
		return -1
	if a[1] < b[1]:
		return -1
	return 0

inputs = sys.stdin.read().split('\n')
k, m, n = map(int, inputs[0].split())
a = inputs[1:]
freq = defaultdict(int)
for s in a:
	freq[s] += 1
items = []
for s in freq:
	items.append((s,freq[s]))

items.sort(cmp=comp, reverse=1)
# print items

for i in xrange(k):
	print items[i][0]

