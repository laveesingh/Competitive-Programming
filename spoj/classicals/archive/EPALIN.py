

# def solve(a):
# 	b = list(reversed(a))
# 	lps = [0]*len(b)
# 	length = 0
# 	i = 0
# 	while i < len(b):
# 		# print "i:",i,"length",length
# 		if a[i]  == b[length]:
# 			length += 1
# 			lps[i] = length
# 			i += 1
# 		else:
# 			if length != 0:
# 				length = lps[length-1] if length != lps[length-1] else lps[length-1]-1
# 			else:
# 				lps[i] = 0
# 				i += 1
# 	trimmed = len(a)-lps[len(a)-1]
# 	# print "trimmed: " ,trimmed
# 	print a+a[trimmed-1::-1] if trimmed > 0 else a

def reverse(a,i,j):
	b = a[i:j+1]
	return b[::-1]

def solve(a):
	if hash(a) == hash(a[::-1]):
		return a
	n = len(a)
	ans = n-1
	for i in xrange(len(a)-1):
		if hash(a[i:]) == hash(reverse(a, i,len(a)-1)):
			ans = i
			break
	return a+a[:ans][::-1]


while 1:
	try:
		a = raw_input()
		if not a:
			print
		else:
			print solve(a)
	except EOFError:
		break