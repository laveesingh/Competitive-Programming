'''input
6 3
5 1
2 1
1 1
8 1
10 0
5 0
'''

I = lambda : map(int, raw_input().split())

n, k = I()

a = []
luck = 0

for i in xrange(n):
	x, y = I()
	if y == 0:
		luck += x
	else:
		a.append(x)
a.sort(reverse=1)
# print a, luck
if k >= len(a):
	luck += sum(a)
else:
	luck += sum(a[:k])
	luck -= sum(a[k:])
print luck