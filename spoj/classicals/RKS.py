from collections import defaultdict

INF = 10**10

class Number:
	def __init__(self, n=0, f=0, fo=INF):
		self.n = n
		self.freq = f
		self.fo = fo
	# def __le__(self, other):
	# 	if self.f < other.f:
	# 		return -1
	# 	if self.f == other.f:
	# 		if self.fo < other.fo:
	# 			return -1
	# 	return 0
	def __repr__(self):
		return "Number(n=%d, frequency=%d, first_occurance=%d)"%(self.n, self.freq, self.fo)


def comp(a, b):
	if a.freq > b.freq:
		return -1
	elif a.freq == b.freq and a.fo < b.fo:
		return -1
	return 0

n, c = map(int, raw_input().split())
a = map(int, raw_input().split())

f = defaultdict(Number)

for i,s in enumerate(a):
	cur = f[s]
	f[s] = Number(s, cur.freq+1, min(i, cur.fo))

temp =  sorted(f.values(), comp)

for s in temp:
	times = s.freq
	num = s.n
	for j in xrange(times):
		print num,

print