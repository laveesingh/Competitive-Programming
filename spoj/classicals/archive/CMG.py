import heapq
import functools

@functools.total_ordering
class Rev(object):
	def __init__(self, obj):
		self.obj = obj
	def __eq__(self, other):
		return isinstance(other, Rev) and self.obj == other.obj
	def __le__(self, other):
		return isinstance(other, Rev) and self.obj >= other.obj
	def __str__(self):
		return str(self.obj)
	def __repr__(self):
		return "%s(%r)"%(self.__class__.__name, self.obj)

def solve():
	n = int(raw_input())
	a = []
	latest = []
	a = map(Rev, a)
	heapq.heapify(a)
	for i in xrange(n):
		query = raw_input().split()
		if len(query) == 2:
			size = int(query[1])
			heapq.heappush(a, Rev(size))
			latest.append(size)
		elif query[0] == 'Q':
			if latest:
				print a[0].obj
			else:
				print "Empty"
		else:
			if latest:
				x = latest.pop()
				i = a.index(Rev(x))
				a[i] = a[-1]
				a.pop()
				try:
					heapq._siftup(a, i)
					heapq._siftdown(a,0,i)
				except IndexError: None


for _ in xrange(input()):
	print "Case %d:"%(_+1)
	solve()