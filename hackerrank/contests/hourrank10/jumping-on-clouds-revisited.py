I = lambda : map(int,raw_input().split())
n, k = I()
a = I()

e = 100

flag = False
i = 0
while i != 0 or flag == False:
	flag = True
	i = (i+k)%n
	if a[i] == 1:
		e -= 2
	e -= 1
print e
