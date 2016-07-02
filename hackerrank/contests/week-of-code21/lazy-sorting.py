n = input()
a = map(int, raw_input().split())

from math import factorial as f
perm = f(n)
tod = 1
for s in set(a):
	x = a.count(s)
	perm /= f(x)
	tod *= x


perm -= tod
perm += 1

print "%d.000000"%perm