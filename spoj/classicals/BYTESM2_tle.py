from collections import defaultdict
import sys


def nextChar():
	ans = ""
	while 1:
		try:
			t = sys.stdin.read(1)
			if t == " " or t == "\n" or t == "\r" or t == "\t":
				if ans:
					return ans
			else:
				ans += t
		except: return ""


def maxpath(i, j, n):
	global a
	global store
	if i == 0:
		return a[i][j]
	if j == 0:
		# print "Catch " if store[(i-1, j)] else 'Miss '
		f = store[(i-1, j)] if store[(i-1, j)] else maxpath(i-1, j, n)
		store[(i-1, j)] = f
		# print "Catch " if store[(i-1, j+1)] else 'Miss '
		s = store[(i-1, j+1)] if store[(i-1, j+1)] else maxpath(i-1, j+1, n)
		store[(i-1, j+1)] = s
		# f = maxpath(i-1, j, n)
		# s = maxpath(i-1, j+1, n)
		if store[(i-1, j)]:
			f = store[(i-1, j)]
		else:
			f = maxpath(i-1, j, n);
			store[(i-1, j)] = f
		if store[(i-1, j+1)]:
			s = store[(i-1, j+1)]
		else:
			s = maxpath(i-1, j+1, n)
			store[(i-1, j+1)] = s

		return a[i][j] + max(f, s)
	if j == n-1:
		# print "Catch " if store[(i-1, j)] else 'Miss '
		f = store[(i-1, j)] if store[(i-1, j)] else maxpath(i-1, j, n)
		store[(i-1, j)] = f
		# print "Catch " if store[(i-1, j-1)] else 'Miss '
		s = store[(i-1, j-1)] if store[(i-1, j-1)] else maxpath(i-1, j-1, n)
		store[(i-1, j-1)] = s
		# f = maxpath(i-1, j, n)
		# s = maxpath(i-1, j-1, n)
		return a[i][j] + max(f, s)
	# print "Catch " if store[(i-1, j)] else 'Miss '
	f = store[(i-1, j)] if store[(i-1, j)] else maxpath(i-1, j, n)
	store[(i-1, j)] = f
	# print "Catch " if store[(i-1, j+1)] else 'Miss '
	s = store[(i-1, j+1)] if store[(i-1, j+1)] else maxpath(i-1, j+1, n)
	store[(i-1, j+1)] = s
	# print "Catch " if store[(i-1, j-1)] else 'Miss '
	t = store[(i-1, j-1)] if store[(i-1, j-1)] else maxpath(i-1, j-1, n)
	store[(i-1, j-1)] = t
	# f = maxpath(i-1, j, n)
	# s = maxpath(i-1, j+1, n)
	# t = maxpath(i-1, j-1, n)
	return a[i][j] + max(f, s, t)

a = []
store = defaultdict(int)
def solve():
	global a
	a = []
	m = int(nextChar())
	#print "m:",m,
	n = int(nextChar())
	#print "n:",n,
	#m, n = map(int, raw_input().split())
	for i in xrange(m):
		temp = [0]*n
		for j in xrange(n):
			temp[j] = int(nextChar())
		a.append(temp)
		#a.append(map(int, raw_input().split()))
	sys.stdout.flush()
	temp = []
	for i in xrange(n):
		temp.append(maxpath(m-1, i, n))
	return max(temp)


t = nextChar()
t = int(t)
#print "t:",t,
for _ in xrange(t):
	print "\b"*(100) + "{0}".format(solve())
	#print solve()


# 1
# 6 5
# 3 1 7 4 2
# 2 1 3 1 1
# 1 2 2 1 8
# 2 2 1 5 3
# 2 1 4 4 4
# 5 2 7 5 1
