n = input()
a = map(int, raw_input().split())

def minimax(a):
	a = list(a)
	return max(a[i]^a[i-1] for i in xrange(1,len(a)))

from itertools import permutations


print min(minimax(perm) for perm in permutations(a))