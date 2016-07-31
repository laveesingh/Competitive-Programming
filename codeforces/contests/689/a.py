
a = [(1,9), (3,7), (0,2), (0,1), (0,3), (1,6,7), (3,4,9), (2,7,9), (1,3,7)]

n = input()
pat = raw_input()
pat = map(int,pat)
pset = set(pat)
flag = "NO"
# print pset
for s in a:
	sset = set(s)
	# print sset
	if sset&pset == sset:
		flag = "YES"
		break
print flag