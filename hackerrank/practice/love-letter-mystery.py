class string(str):
	def __sub__(self, a):
		return abs(ord(self)-ord(a))

def solve(a):
	b = [string(s) for s in a]
	ans = 0
	for i in xrange(len(b)/2):
		ans += (b[i]-b[len(b)-i-1])
	return ans

for _ in xrange(input()):
	print solve(raw_input())