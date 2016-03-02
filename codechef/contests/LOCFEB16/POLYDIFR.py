import operator
def diff(cof, exp):
	if cof == 0 or exp == 0: return (0,0)
	cof *= exp
	exp -= 1
	return (cof, exp)

def deco(cof, exp):
	if cof == 0: return ""
	if exp == 0:
		return `abs(cof)`

	return `abs(cof)` + "x^" + `exp`



for _ in xrange(input()):
	n = input()
	ans = []
	res = []
	for __ in xrange(n):
		c, e = map(int,raw_input().split())
		res.append(diff(c, e))

		# x = deco(*diff(c, e))
		# if x:
		# 	ans.append(x)

	res.sort(key=operator.itemgetter(1), reverse=True)

	for s in res:
		x  = deco(*s)
		if x:
			ans.append(x)
	print " + ".join(ans)
