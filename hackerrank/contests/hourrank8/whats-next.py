def solve(a):
	if len(a) == 1:
		b = [1,1]
		if a[0] > 1: b.append(a[0]-1)
		return b
	if len(a) == 2:
		b = [1, a[1]+1]
		if a[0] > 1: b.append(a[0]-1)
		return b
	if len(a)%2 != 0:
		b = [s for s in a[:-2]]
		if a[-2] == 1:
			b[-1] += 1
			b.append(1)
		else:
			b.append(a[-2]-1)
			b.append(1)
			b.append(1)
		if a[-1] > 1:
			b.append(a[-1]-1)
		return b
	if len(a)%2 == 0:
		if a[-2] == 1 and a[-3] == 1:
			b = [s for s in a[:-3]]
			b[-1] += 1
			b.append(a[-1]+1)
			return b
		if a[-3] == 1:
			b = [s for s in a[:-3]]
			b[-1] += 1
			b.append(a[-1]+1)
			b.append(a[-2]-1)
			return b
		elif a[-2] == 1:
			a[-3] -=1 
			a[-1] += 1
			return a
		else:
			b = [s for s in a[:-2]]
			b[-1] -= 1
			b.append(1)
			b.append(a[-1]+1)
			b.append(a[-2]-1)
			return b
	return []

for _ in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	b = solve(a)
	print len(b)
	for s in b: print s,
	print