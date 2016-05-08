from collections import defaultdict
n = input()
a = []
mema = set()
tot = 0
first = defaultdict(int)
second = defaultdict(int)
for _ in xrange(n):
	x = tuple(map(int, raw_input().split()))
	if x in mema:
		tot += 1
	first[x[0]] += 1
	second[x[1]] += 1
	a.append(x)
	mema.add(x)
ans = 0
def fact(x):
	return sum(range(x))
# print first
# print second
for s in first:
	ans += fact(first[s])
for s in second:
	ans += fact(second[s])
print ans-tot

