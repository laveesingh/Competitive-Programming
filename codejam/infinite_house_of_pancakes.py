
time = 0
def part(a):
	global time
	if a == 4:
		time += 1
		return [2,2]
	else:
		d = []
		while a > 3:
			if a == 4:
				d += [2,2]
				time += 1
				break
			else:
				d.append(3)
				a -= 3
				time += 1
		return d

def solve(a):
	global time
	time = 0
	b = []
	for s in a:
		if s <= 3:
			b.append(s)
		else:
			b += part(s)
	time += max(b)
	return time

inputs = []

for _ in xrange(input()):
	d = input()
	a = map(int, raw_input().split())
	inputs.append(a)

for i,a in enumerate(inputs):
	print "Case #%d:"%(i+1),solve(a)
