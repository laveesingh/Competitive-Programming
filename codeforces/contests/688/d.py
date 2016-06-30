I = lambda : map(int, raw_input().split())
n, k = I()

a = I()
ans = "No"
for s in a:
	if k%s == 0:
		ans = "Yes"
		break
print ans