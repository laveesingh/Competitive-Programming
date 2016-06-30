n = input()
a = map(int, raw_input().split())

from math import factorial as f
perm = f(n)
for s in set(a):
	perm /= f(a.count(s))

print "%d.000000"%perm