
def solve(a, b):
	a = list(a)
	b = list(b)
	n = len(a)
	for i in xrange(n):
		if i == 0:
			if a[i] == '?' and b[i] == '?':
				if len(a) == 1:
					a[i] = 0
					b[i] = 0
				elif a[i+1] == '?' or b[i+1] == '?':
					a[i] = 0
					b[i] = 0
				else:
					if abs(int(a[i+1])-int(b[i+1])) > 5:
						if int(a[i+1]) > int(b[i+1]):
							b[i] = 1
							a[i] = 0
						else:
							a[i] = 1
							b[i] = 0
					else:
						a[i] = 0
						b[i] = 0
			elif a[i] == '?':
				if len(a) == 1:
					a[i] = b[i]
				else:
					if a[i+1] == '?' or b[i+1] == '?' or a[i+1] == b[i+1]:
						a[i] = b[i]
					elif int(b[i+1]) > int(a[i+1]):
						if int(b[i+1])-int(a[i+1]) > 5:
							a[i] = int(b[i])+1
						else:
							a[i] = b[i]
					else:
						if int(a[i+1])-int(b[i+1]) < 5:
							a[i] = b[i]
						else:
							a[i] = int(b[i]) - 1
			elif b[i] == '?':
				if len(b) == 1:
					b[i] = a[i]
				else:
					if a[i+1] == '?' or b[i+1] == '?' or a[i+1] == b[i+1]:
						b[i] = a[i]
					elif int(a[i+1]) > int(b[i+1]):
						if int(a[i+1])-int(b[i+1]) > 5:
							b[i] = int(a[i])+1
						else:
							b[i] = a[i]
					else:
						if int(b[i+1])-int(a[i+1]) < 5:
							b[i] = a[i]
						else:
							b[i] = int(a[i]) - 1


		else:
			if a[i] == '?':
				if a[:i] == b[:i]:
					if b[i] == '?':
						if i == n-1:
							a[i] = 0
						else:
							if a[i+1] == '?' or b[i+1] == '?' or a[i+1]  == b[i+1]:
								a[i] = 0
							else:
								if int(b[i+1]) - int(a[i+1]) > 5:
									a[i] = 1
									b[i] = 0
								else:
									a[i] = 0
									b[i] = 0
					else:
						if i == n-1:
							a[i] = b[i]
						else:
							if a[i+1] == '?' or b[i+1] == '?' or a[i+1]  == b[i+1]:
								a[i] = b[i]
							else:
								if int(a[i+1]) > int(b[i+1]) and int(a[i+1])-int(b[i+1])>=5:
									a[i] = int(b[i])-1
								elif int(b[i+1])>int(a[i+1]) and int(b[i+1])-int(a[i+1]) >= 5:
									a[i] = int(b[i])+1
								else:
									a[i] = b[i]


				else:
					if int(''.join([str(s) for s in a[:i]])) > int(''.join([str(s) for s in b[:i]])):
						a[i] = 0
					else:
						a[i] = 9
			if b[i] == '?':
				if b[:i] == a[:i]:
					if a[i] == '?':
						if i == n-1:
							b[i] = 0
						else:
							if b[i+1] == '?' or a[i+1] == '?' or a[i+1]  == b[i+1]:
								b[i] = 0
							else:
								if int(a[i+1]) - int(b[i+1]) > 5:
									b[i] = 1
									a[i] = 0
								else:
									b[i] = 0
									a[i] = 0
					else:
						if i == n-1:
							b[i] = a[i]
						else:
							if a[i+1] == '?' or b[i+1] == '?' or a[i+1]  == b[i+1]:
								b[i] = a[i]
							else:
								if int(b[i+1]) > int(a[i+1]) and int(b[i+1])-int(a[i+1])>=5:
									b[i] = int(a[i])-1
								elif int(a[i+1])>int(b[i+1]) and int(a[i+1])-int(b[i+1]) >= 5:
									b[i] = int(a[i])+1
								else:
									b[i] = a[i]


				else:
					if int(''.join([str(s) for s in b[:i]])) > int(''.join([str(s) for s in a[:i]])):
						b[i] = 0
					else:
						b[i] = 9
	x = ''.join([str(s) for s in a])
	y = ''.join([str(s) for s in b])
	return (x,y)

inputs = []
for _ in xrange(input()):
	inputs.append(raw_input())

for i in xrange(len(inputs)):
	st = inputs[i].split()
	s1 = st[0]
	s2 = st[1]
	ans = solve(s1, s2)
	print "Case #%d: %s %s"%(i+1, ans[0], ans[1])