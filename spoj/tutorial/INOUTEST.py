
ai = lambda : map(int, raw_input().split())
import sys
for _ in xrange(int(raw_input())):
	x, y = ai()
	print x*y
