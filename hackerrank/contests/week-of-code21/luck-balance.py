import operator

I = lambda : map(int, raw_input().split())

n, k = I()

ans = 0

iContests = []

for i in xrange(n):
	x, y = I()
	if y == 0:
		ans += x
	else:
		iContests.append((x,y))

iContests.sort(reverse=True)

# print ans
# print iContests

if len(iContests) >= k:
	for i in xrange(k):
		ans += iContests[i][0]
	for i in xrange(k,len(iContests)):
		ans -= iContests[i][0]
else:
	for s in iContests:
		ans += s[0]

print ans