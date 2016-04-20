

def solve(a):
	b = a[::-1]
	i = 0
	j = 0
	while i < len(a):
		if a[i] == b[j]:
			i += 1
			j += 1
		else:
			if a[i] == b[0]:
				j = 0
			else:
				j = 0
				i += 1
	if j < len(a):
		return a+b[j:]
	return a

while 1:
	try:
		x = raw_input().strip()
		if not x: break
		print solve(x)
	except: break