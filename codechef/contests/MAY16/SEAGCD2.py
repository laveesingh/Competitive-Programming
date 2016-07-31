from fractions import gcd as g1
from math import factorial as fact
from itertools import permutations
from collections import defaultdict

MOD = 10**9 + 7
vis = defaultdict(int)

def comb(n,i):
	return fact(n)/(fact(n-i)*fact(i))

def gcd(*a):
	return reduce(g1, a)

def permute(a, vis):
	freq = defaultdict(int)
	ans = 0
	for s in permutations(a):
		if not vis[hash(tuple(s))]:
			# print "not visited", tuple(s)
			ans += 1
			vis[hash(tuple(s))] = 1
	return ans

def ones(a, vis):
	ans = 0
	for i in xrange(1,len(a)):
		for j in xrange(i,len(a)):
			try:
				b = a[:i]+(1,)*len(a[i:j+1])+a[j+1:]
				# print "b:",b,
				x = permute(b, vis)
				ans += x
				# print "added: ",x,"permute"
			except IndexError: None
	return ans


def solve(n, m):
	global vis
	vis.clear()
	m += 1
	ans = []
	if n == 1:
		return 1
	elif n == 2:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				if gcd(a,b) == 1:
					ans.append((a,b))
	elif n == 3:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					if gcd(a,b,c) == 1:
						ans.append((a,b,c))
	elif n == 4:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					for d in xrange(c+1,m):
						if gcd(a,b,c,d) == 1:
							ans.append((a,b,c,d))
	elif n == 5:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					for d in xrange(c+1,m):
						for e in xrange(d+1,m):
							if gcd(a,b,c,d,e) == 1:
								ans.append((a,b,c,d,e))
	elif n == 6:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					for d in xrange(c+1,m):
						for e in xrange(d+1,m):
							for f in xrange(e+1,m):
								if gcd(a,b,c,d,e,f) == 1:
									ans.append((a,b,c,d,e,f))
	elif n == 7:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					for d in xrange(c+1,m):
						for e in xrange(d+1,m):
							for f in xrange(e+1,m):
								for g in xrange(f+1,m):
									if gcd(a,b,c,d,e,f,g) == 1:
										ans.append((a,b,c,d,e,f,g))
	elif n == 8:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					for d in xrange(c+1,m):
						for e in xrange(d+1,m):
							for f in xrange(e+1,m):
								for g in xrange(f+1,m):
									for h in xrange(g+1,m):
										if gcd(a,b,c,d,e,f,g,h) == 1:
											ans.append((a,b,c,d,e,f,g,h))
	elif n == 9:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					for d in xrange(c+1,m):
						for e in xrange(d+1,m):
							for f in xrange(e+1,m):
								for g in xrange(f+1,m):
									for h in xrange(g+1,m):
										for i in xrange(h+1, m):
											if gcd(a,b,c,d,e,f,g,h,i) == 1:
												ans.append((a,b,c,d,e,f,g,h,i))
	elif n == 10:
		for a in xrange(1,m):
			for b in xrange(a+1,m):
				for c in xrange(b+1,m):
					for d in xrange(c+1,m):
						for e in xrange(d+1,m):
							for f in xrange(e+1,m):
								for g in xrange(f+1,m):
									for h in xrange(g+1,m):
										for i in xrange(h+1, m):
											for j in xrange(i+1,m):
												if gcd(a,b,c,d,e,f,g,h,i,j) == 1:
													ans.append((a,b,c,d,e,f,g,h,i,j))

	res = 0
	for s in ans:
		# print "s:",s,
		vis[tuple(s)] = 1
		n = len(s)
		res += fact(n)
		# print "res:",res,
		if 1 in s:
			x = ones(s, vis)	
			res += x
			# print "added ", x, 'ones'


	return res

for _ in xrange(input()):
	n , m = map(int, raw_input().split())
	print solve(n,m)%MOD




