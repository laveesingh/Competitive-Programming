import sys

a = sys.stdin.read().split('\n')

from collections import defaultdict

d = defaultdict(int)

for s in a:
	d[s] += 1

vals = d.values()
for s in sorted(vals, reverse=1):
	print s