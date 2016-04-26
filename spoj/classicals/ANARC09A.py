from UserString import MutableString

def solve(a):
	a = MutableString(a)
	ans = 0
	while len(a) > 0:
		a = a.replace("{}","")
		if a and "{}" not in a:
			if a[0] == '}' and a[-1] == '{':
				ans += 2
				a[0]  = '{'
				a[-1] = '}'
			elif a[0] == '}':
				ans += 1
				a[0] = '{'
			elif a[-1] == '{':
				ans += 1
				a[-1] = '}'
	return ans
i = 1
while 1:
	a = raw_input()
	if a[0] == '-':
		break
	print "%d. %d"%(i, solve(a))
	i += 1
