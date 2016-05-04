
def solve(a):
	digits = []
	a = list(a)
	while len(a) > 2:
		if 'Z' in a:
			digits.append(0)
			del a[a.index('Z')]
			del a[a.index('E')]
			del a[a.index('R')]
			del a[a.index('O')]

		if 'X' in a:
			digits.append(6)
			del a[a.index('S')]
			del a[a.index('I')]
			del a[a.index('X')]
		if 'G' in a:
			digits.append(8)
			del a[a.index('G')]
			del a[a.index('E')]
			del a[a.index('I')]
			del a[a.index('H')]
			del a[a.index('T')]
		if 'W' in a:
			digits.append(2)
			del a[a.index('W')]
			del a[a.index('T')]
			del a[a.index('O')]
		if 'U' in a:
			digits.append(4)
			del a[a.index('U')]
			del a[a.index('F')]
			del a[a.index('O')]
			del a[a.index('R')]
		if 'F' in a and not 'U' in a:
			digits.append(5)
			del a[a.index('F')]
			del a[a.index('I')]
			del a[a.index('V')]
			del a[a.index('E')]
		if 'S' in a and not 'X' in a:
			digits.append(7)
			del a[a.index('S')]
			del a[a.index('E')]
			del a[a.index('V')]
			del a[a.index('E')]
			del a[a.index('N')]
		if 'H' in a and not 'G' in a:
			digits.append(3)
			del a[a.index('T')]
			del a[a.index('H')]
			del a[a.index('R')]
			del a[a.index('E')]
			del a[a.index('E')]

		if 'O' in a and not 'Z' in a and not 'W' in a and not 'U' in a:
			digits.append(1)
			del a[a.index('O')]
			del a[a.index('N')]
			del a[a.index('E')]
		if 'N' in a and not 'O' in a and not 'V' in a:
			digits.append(9)
			del a[a.index('E')]
			del a[a.index('N')]
			del a[a.index('I')]
			del a[a.index('N')]
		# print a
	return ''.join([str(s) for s in sorted(digits)])

inputs = []
for _ in xrange(input()):
	inputs.append(raw_input())

for i in xrange(len(inputs)):
	print "Case #%d: %s"%(i+1, solve(inputs[i]))

