from collections import OrderedDict

def isPal(n):
	return str(n) == str(n)[::-1]

palindromes = []
for i in xrange(100, 1000):
	for j in xrange(100, 1000):
		x = i*j
		if isPal(x):
			palindromes.append(x)

palindromes.sort()

inputs = OrderedDict()
for _ in xrange(input()):
	inputs[input()] = 0

for s in inputs:
	for t in palindromes[::-1]:
		if t < s:
			inputs[s] = t
			break

for s in inputs:
	print inputs[s]

