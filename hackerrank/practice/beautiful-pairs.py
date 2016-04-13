from collections import defaultdict

def fract(a, b):
	fra = defaultdict(int)
	maxo = 1
	maxa = a[0]
	for s in a:
		fra[s] += 1
		if fra[s] > maxo:
			maxa = s

	fra2 = defaultdict(int)

	for i,s in enumerate(b):
		fra2[s] = fra[s]

	mina = min(fra2.values())
	tori = []
	for i in xrange(len(b)):
		if fra2[b[i]] == mina:
			tori.append(i)

	for i in tori:
		if b[i] != maxa:
			b[i] = maxa
			break
	else:
		b[tori[0]] = maxa
	return (a,b)

def beauty(a, b):
	bpl = []
	for i in xrange(len(a)):
		for j in xrange(len(b)):
			if a[i] == b[j]:
				bpl.append((i,j))
	isthere = defaultdict(int)
	for s in bpl: isthere[s] = 1
	count = 0
	# flag = 0
	xs = defaultdict(int)
	ys = defaultdict(int)
	for i in xrange(len(a)):
		for j in xrange(len(b)):
			if isthere[(i,j)]:
				count += 1
				# flag = 1
				break
	return count

I = lambda : map(int, raw_input().split())

n = input()
a = I()
b = I()
print beauty(*fract(a,b))

