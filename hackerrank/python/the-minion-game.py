def vowel(a):
	if a in 'AEIOU':
		return True
	return False

kev = 0
st = 0
for i in xrange(len(a)):
	if vowel(a[i]):
		kev += len(a)-i
	else:
		st += len(a)-i
if kev > st:
	print "Kevin",kev
elif st > kev:
	print "Stuart",st
else: print "Draw"