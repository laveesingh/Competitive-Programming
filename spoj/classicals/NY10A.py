from collections import defaultdict

seq = ["TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"]

def solve(a, n):
	store = defaultdict(int)
	cur = ''
	for s in a:
		cur += s
		for t in seq:
			#print store
			if cur == t:

				store[t] += 1
				cur = cur[1:]
	print n,
	for s in seq:
		print store[s],
	print

for _ in xrange(input()):
	n = input()
	a = raw_input()
	solve(a, n)
