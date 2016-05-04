n = input()
a = map(int, raw_input().split())
i = 0
ans = 0
while (1):
	if i == len(a)-1:
		break
	if i == len(a)-2:
		i += 1
		ans += 1
	else:
		if a[i+2] == 1:
			i += 1
		else:
			i += 2
		ans += 1

print ans