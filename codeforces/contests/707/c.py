n = input()

if n == 1 or n == 2:
	print -1
elif n%2:
	mid = n**2
	mid /= 2
	print mid, mid+1
else:
	mid = n/2
	mid = mid**2
	print mid-1, mid+1