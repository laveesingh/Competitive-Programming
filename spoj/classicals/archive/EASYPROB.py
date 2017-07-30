from math import log
def l(n):
	return int(log(n, 2))

def bdown(n):
	a = []
	while n > 0:
		a.append(l(n))
		n -= 2**l(n)
	return a

# n = input()
# store = bdown(n)
# print store
def l1():
	global store
	for i in xrange(len(store)):
		if store[i] != 1 and store[i] != 0:
			store[i] = bdown(store[i])

# print store
def l2():
	global store
	for i in xrange(len(store)):
		if store[i] != 1 and store[i] != 0:
			for j in xrange(len(store[i])):
				if store[i][j] != 1 and store[i][j] != 0:
					store[i][j] = bdown(store[i][j])


# ans = ""
def pprint(a):
	global ans
	for s in a:
		if type(s) == int:
			if s == 1:
				ans += "2+"
			else:
				ans += "2("+str(s)+")+"
		else:
			ans += "2("
			pprint(s)
			ans += ")+"

ans=None
store=None
list_of_ints = [137, 1315, 73, 136, 255, 1384, 16385]
for n in list_of_ints:
	store = bdown(n)
	ans = ""
	l1()
	l2()
	pprint(store)
	
	ans = ans.replace("+)",")")
	print "{0}={1}".format(n,ans[:-1])

