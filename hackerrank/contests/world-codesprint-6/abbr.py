'''input
5
daBcd
ABC
Vis
IS
VISA
VISH
aAAaA
AA
AABA
AAA
'''


from UserString import MutableString

def rec(a, b, i):
	if not b:
		for s in a[i:]:
			if s.isupper():
				return 0
		return 1
	if i == len(a): return 0
	if a[i] == b[0]:
		return rec(a, b[1:], i+1)
	if a[i].upper()  == b[0]:
		return (rec(a, b, i+1) or rec(a, b[1:], i+1))
	if a[i].isupper(): return False
	return rec(a, b, i+1)
	


for _ in xrange(input()):
	a = raw_input()
	b = raw_input()
	if rec(a, b, 0):
		print "YES"
	else: print "NO"