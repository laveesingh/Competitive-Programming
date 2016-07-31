def solve(a):
	a = list(a)
	count = 0
	for i in xrange(2,len(a)):
		if a[i-2] == '0' and a[i-1] == '1' and a[i] == '0':
			a[i] = '1'
			count += 1
	return count


n = input()
a = raw_input()
print solve(a)