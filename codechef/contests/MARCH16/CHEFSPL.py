
# def solve(a):
# 	if not len(a)%2:
# 		return a[:(len(a)/2)] == a[(len(a)/2):]
# 	for i in xrange(len(a)):
# 		b = solve(a[:i] + a[i+1:]) if i < len(a)-1 else solve(a[:i])
# 		if b == True: return True
# 	return False

from collections import defaultdict
import random

def solve(a):
	if not len(a)%2 and len(a) >= 1000:
		indx = [random.randint(0, len(a)/2) for i in xrange(10)]
		i = len(a)/2
		indy = [(s+i) for s in indx]
		boolarray = []
		for x,y in zip(indx, indy):
			try:
				if a[x] != a[y]: return False
			except IndexError: None
		for i in xrange(len(a)-1, len(a)-100):
			try:
				if not a[x] == a[y]: return False
			except IndexError: None
		return True

	elif not len(a)%2:
		return a[:(len(a)/2)] == a[(len(a)/2):]

	freq = defaultdict(int)
	for s in a:
		freq[s] += 1
	elm = None
	for s in freq:
		if freq[s]%2:
			elm = s
			break
	for i in xrange(len(a)):
		if a[i] == elm:
			b = solve(a[:i] + a[i+1:]) if i < len(a)-1 else solve(a[:i])
			if b: return True
	return False

import sys
t=int(sys.stdin.readline())
for _ in xrange(t):
	sys.stdout.write(("YES\n" if solve(raw_input()) else "NO\n"))