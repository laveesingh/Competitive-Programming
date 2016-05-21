n = input()
a = map(int, raw_input().split())

op = 0
if len(a) > 1:
	i = 0
	while i < len(a) and a[i] <= 0 :
		i += 1
	if i < len(a):
		a = a[i:]+a[:i]

	i = len(a)-1
	curt = 0
	while (a[i] <= 0 and curt <= a[i]):

	if a[0] != 0 and a[0] + a[-1] == 0:
		op += 1
		a[0] = 0
		a[-1] = 0

total = 0
total_zeros = 0
for i in xrange(0,len(a)):
	if total == 0 and a[i] == 0:
		None
	else:
		total += a[i]
		a[i] = total
		if a[i] != 0:
			op += 1
print op
