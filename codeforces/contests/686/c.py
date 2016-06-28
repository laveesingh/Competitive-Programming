from math import log,floor
from itertools import permutations

def represent(n):
    a = []
    while n > 0:
        a.append(n%7)
        n /= 7
    a = a[::-1]
    a = [str(s) for s in a]
    return ''.join(a)


def base_length(n):
	if n == 1: return 1
	return int(floor(log(n-1, 7)))+1
	# return len(represent(n))


def main():
	n, m = map(int, raw_input().split())
	l1 = base_length(n)
	l2 = base_length(m)
	# print l1, l2
	if l1 + l2 > 7:
		print 0
		return
	digits = '0123456'
	npos = list(permutations(digits, l1))
	mpos = list(permutations(digits, l2))
	count = 0
	for s in npos:
		sset = set(s)
		# print ''.join(s)
		if len(sset) == len(s) and int(''.join(s), 7) < n:
			for t in mpos:
				# print ''.join(s), ''.join(t)
				tset = set(t)
				if len(tset) == len(t) and not (sset & tset) and int(''.join(t), 7) < m:
					# print ''.join(s), ''.join(t)
					count += 1
	print count

main()

