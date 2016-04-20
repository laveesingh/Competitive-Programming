def solve(a):
	i = 1
	flag = 1
	while flag == 1:
		flag = 0
		i = 1
		while i < len(a):
			if a[i] == a[i-1]:
				flag = 1
				del a[i]
				del a[i-1]
			else: i += 1
	return ''.join(a) if a else "Empty String"

print solve(list(raw_input()))