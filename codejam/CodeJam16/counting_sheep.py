
def solve(n):
	f = {}
	for i in xrange(1,100000):
		temp = str(n*i)
		for s in temp:
			f[s] = 1
		if len(f) == 10:
			return temp
	return "INSOMNIA"

inputs = []

for _ in xrange(input()):
	inputs.append(input())

for i,s in enumerate(inputs):
	print "Case #%d:"%(i+1),solve(s)