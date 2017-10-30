
a = raw_input()

b = "SOS"*(len(a)/3)

diff = 0

for i in xrange(len(a)):
	if a[i] != b[i]:
		diff += 1
print diff