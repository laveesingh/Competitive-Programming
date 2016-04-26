
def solve(a):
	ans = 0
	cur = 0
	for i in xrange(len(a)):
		if i > cur:
			ans += i-cur
			cur += i-cur
			cur += int(a[i])
		else:
			cur += int(a[i])
	return ans
inputs = []
for _ in xrange(input()):
	x, a = raw_input().split()
	inputs.append(a)
for i,a in enumerate(inputs):
	print "Case #%d: %d"%(i+1,solve(a))