'''input
10
2 9 2 8 6 8 7 3 10 9
5
3 5 7 7 10
'''


I = lambda : map(int, raw_input().split())

n = input()
h = I()
m = input()
l = [s-1 for s in I()]

for i in xrange(m):
	j = l[i]
	for rj in xrange(j-1, -1, -1):
		h[rj] = min(h[rj], j-rj)
print sum(h)