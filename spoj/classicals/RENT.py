import functools
from collections import defaultdict

@functools.total_ordering
class job:
	def __init__(self, start, end, cost):
		self.start = start
		self.end = end
		self.cost = cost



	def __le__(self, other):
		if self.end < other.end:
			return True
		else:
			return self.start < other.start

	def __repr__(self):
		return "%s(start=%d,end=%d,cost=%d)"%(self.__class__.__name__, self.start, self.end, self.cost)

# a = None #global a for jobs sequence

store = defaultdict(int)

def solve(n, end):
	global a
	x = store[(n,end)]
	if x: return x
	if n == 1:
		if a[n-1].start >= end:
			return a[n-1].cost
		else:
			return 0
	else:
		x = solve(n-1, end)
		store[(n-1, end)] = x
		if a[n-1].start >= end:
			y = solve(n-1, a[n-1].end)
			store[(n-1, a[n-1].end)] = y
			x = max(x, a[n-1].cost+y)
		return x

# def solve():
# 	cost = 0
# 	end = 0
# 	for i in xrange(len(a)):
# 		if a[i].start >= end:
# 			end = a[i].end
# 			cost += a[i].cost
# 	return cost

for _ in xrange(int(raw_input())):
	n = int(raw_input())
	a = []
	for i in xrange(n):
		x, y, z = map(int, raw_input().split())
		a.append(job(x, y+x, z))
	a.sort()
	print solve(len(a),0)
	del store