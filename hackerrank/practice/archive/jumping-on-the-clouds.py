'''input
6
0 0 0 0 1 0
'''

n = input()
a = map(int, raw_input().split())

cnt = 0
i = 0
while i < n-1:
	if i + 2 < n:
		if a[i+2]==0:
			i += 2
		else:
			i += 1
		cnt += 1
	else:
		cnt += 1
		i += 1
print cnt

