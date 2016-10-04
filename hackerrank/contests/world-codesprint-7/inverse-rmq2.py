import math, collections

n = input()
T = map(int, raw_input().split())

def recgood(node, b):
	if node*2 + 1 >= len(b):
		return 1
	if b[node] > b[node*2] or b[node] > b[node*2+1]:
		print b[node], b[node*2], b[node*2+1]
		return 0
	return recgood(node*2, b) and recgood(2*node+1, b)

def good(b):
	if len(b[-n:]) != len(set(b[-n:])):
		# print "Not unique"
		return 0
	return recgood(1, b)

def comp(x, y):
	if x[0] == y[0]:
		if x[1] > y[1]:
			return -1
		else:
			return 1
	if x[0] < y[0]:
		return -1
	return 1

b = [0]*(2*n)
def solve(node, a):
	'''"a" is a reverse frequency table'''
	# print a,
	par = a.pop()
	b[node] = par[1]
	if(par[0] <= 1): return
	par = (par[0]-1, par[1])
	a.append(par)
	if a[-1][1] < a[-2][1]:
		a[-1], a[-2] = a[-2], a[-1]
	# print "After removal: ",a
	right = a.pop()
	left = a.pop()
	freq = right[0]- 1
	a0 = [left]
	a1 = [right]
	while freq > 0:
		temp  = []
		# while a and a[-1][0] == freq:
			# temp.append(a.pop())
		I = len(a)-1
		while (I >= 0 and a[I][0] == freq):
			I -= 1
		I += 1
		temp.extend(a[I:])
		# print "Current temp:",temp
		a = a[:I]
		freq -= 1
		# temp = temp[::-1]
		if len(a0) == 0:
			a0.append(temp.pop())
			a1.append(temp.pop()) # I think sorting is not necessarily required here
		else:
			i = len(a0)-1
			j = len(a1)-1
			# print "temp:",temp, "a0:",a0,"a1:",a1
			while i >= 0 or j >= 0:
				if j >= 0 and a1[j][1] > a0[i][1]:
					a1.append(temp.pop())
					j -= 1
				else:
					a0.append(temp.pop())
					i -= 1
		a0.sort(key=lambda x: x[1])
		a1.sort(key=lambda x: x[1])
		# print "a0:",a0
		# print "a1:",a1

	a0.sort()
	a1.sort()
	if len(a0) != len(a1):
		raise NameError("The two aren't equal")
		return
	solve(2*node, a0)
	solve(2*node+1, a1)

cnt = collections.Counter(T)
a = [(cnt[s],s) for s in cnt] # reverse frequency table
a.sort()
back_a = a[:]
# print "a:",a
try:
	solve(1, a)
except:
	None

# print b
if good(b):
	print "YES"
	b = [None for i in xrange(2*n)]
	back_a.sort(cmp=comp)
	# print "back_a:",back_a
	node = 1
	while back_a:
		cur = back_a.pop()
		# print "cur:",cur
		node2 = node
		while node2 < len(b) and b[node2] != None:
			node2 += 1
		node = node2
		while node2 < len(b):
			b[node2] = cur[1]
			node2 *= 2
	for i in xrange(1,len(b)):
		print b[i],
	print
else:
	print "NO"