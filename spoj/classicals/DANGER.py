from math import log

def des2(n):
	cnt = 0
	while n:
		cnt += 1
		n/= 2
	return 2**(cnt-1)


def solve(n):
	x = des2(n)
	# print "x:",x
	t = (n-x)/2
	if n%2:
		if n == 1:
			ans = n
		else:
			ans = 4*t+3
	else:
		ans = 4*t+1
		# ans = ans if ans != -1 else 1
	return ans


while(1):
	# print "Enter a"
	a = raw_input()
	if a == "00e0":
		break
	else:
		a = a.split('e')
		n = int(a[0], 10)
		e = int(a[1])
		n *= 10**e
		# print "The number is:",n
		print solve(n)