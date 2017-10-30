'''input
3
2 4
2 8
5 9
'''

def dp(i):
	if i == 0: return 0
	temp = [i, i, 2, 2, i+2, i+2, 0, 0]
	return temp[i%8]
for _ in xrange(input()):
	l, r = map(int,raw_input().split())
	print dp(l-1)^dp(r)