'''input
10 1 2
4
50
100
10
20
'''


l, v1, v2 = map(float, raw_input().split())
v = abs(v1-v2)
k = l * 2**0.5

q = int(raw_input())

for _ in xrange(q):
	area = float(raw_input())
	cs = (area*2)**0.5
	# print "Common side",cs,"common rectangle side"
	d = abs(k - cs)
	t = d/v
	print "%0.4f"%t