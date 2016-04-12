from collections import defaultdict
from pprint import pprint
MAX = 10**9 + 7
def setters(a, s):
	sub = []
	for i in xrange(len(s)):
		if s[i] == '1':
			sub.append(a[i])
	return sub

def powerset(a):
	pset = []
	for i in xrange(1,2**len(a)):
		s = bin(i)[2:].zfill(len(a));
		# print "bin:",s,"sub:",
		sub = setters(a,s);
		# print sub
		pset.append(sub)
	return pset
fibs = defaultdict(int)

def fib_set():
	global fibs
	i, a, b = 0, 0, 1
	while i <= 10**7:
		fibs[i] = a
		a, b = b, a+b
		i += 1
fib_set()


def F(a):
	ans = 0
	# a = map(int, raw_input("Please enter the array:").split())
	for si in powerset(a):
		x = sum(si)
		f = fibs[x]
		# print "Si:",si,"sum:",x,"Fib:",f
		ans += f
	return ans

a = map(int, raw_input().split())
print F(a)