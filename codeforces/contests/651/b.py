from collections import defaultdict

def solve(a):
	a.sort()
	freq = defaultdict(int)
	maxf = 0
	for s in a:
		x = freq[s]
		x += 1
		freq[s] = x
		if x > maxf:
			maxf = x

	cf = defaultdict(int)

	v = []
	for i in xrange(maxf):
		for s in a:
			if cf[s] == i and freq[s] >= i+1:
				cf[s] += 1
				v.append(s)
	n = len(v)
	ans = 0
	for i in xrange(n-1):
		if v[i] < v[i+1]:
			ans += 1
	return ans

n = input()

print solve(map(int, raw_input().split()))