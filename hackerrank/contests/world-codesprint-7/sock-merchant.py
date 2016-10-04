import collections as cl

n = input()
a = map(int, raw_input().split())
ac = cl.Counter(a)
ans = 0
# print ac
for s in ac:
	ans += ac[s]/2
print ans