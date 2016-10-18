rep = 0

n = input()
a = map(int, raw_input().split())
ans = 0
if n > 50
while a:
	b = []
	for x in a:
		for y in a:
			if x != y: b.append(abs(x-y))
	rep += 1
	a = b
	if rep > 1000 and len(a) > n:
		ans = -1
		break

if ans == -1:
	print ans
else:
	print rep
