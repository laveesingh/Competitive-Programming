
class order:
	def __init__(self, n, start, duration):
		self.start = start
		self.n = n
		self.duration = duration
		self.end = start+duration
	def __repr__(self):
		string = "number:%d start:%d end:%d"%(self.n, self.start, self.end)
		return string

def compare(a, b):
	if a.end == b.end:
		return -1 if a.n < b.n else 0
	return -1 if a.end < b.end else 0


n = input()
a = []
for s in xrange(1,n+1):
	start, duration = map(int,raw_input().split())
	a.append(order(s,start, duration))
a.sort(compare)
for s in a:
	print s.n,
print

