
def lps(a):
	l = 0
	i = 1
	n = len(a)
	arr = [0]*n
	while i < n:
		if a[i] == a[l]:
			l += 1
			arr[i] = l
			i += 1
		else:
			if l != 0:
				l = arr[l-1]
			else:
				arr[i] = 0
				i += 1
	return arr

txt = raw_input()
print lps(txt)