from collections import defaultdict

def solve(a, b):
	k = 0
	visited = defaultdict(int)
	for i in xrange(len(a)):
		for j in xrange(len(b)):
			if not visited[j] and a[i] == b[j]:
				visited[j] = 1
				k += 1
				break
	return k-1 if k == len(a) else k+1

n = input()
a = map(int, raw_input().split())
b = map(int, raw_input().split())
print solve(a, b)
