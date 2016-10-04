import math, collections

n = input()
T = map(int, raw_input().split())

def recgood(node, b):
	if node*2 + 1 >= len(b):
		return 1
	if b[node] > b[node*2] or b[node] > b[node*2+1]:
		return 0
	return recgood(node*2, b) and recgood(2*node+1, b)

def good(b):
	if len(b[-n:]) != len(set(b[-n:])):
		return 0
	return recgood(1, b)

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
		while a and a[-1][0] == freq:
			temp.append(a.pop())
		freq -= 1
		a1 += temp[:len(temp)/2] #temp would be reverse of what we need
		a0 += temp[len(temp)/2:]
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
try:
	solve(1, a)
except:
	None
if good(b):
	print "YES"
	for i in xrange(1,len(b)):
		print b[i],
	print
else:
	print "NO"