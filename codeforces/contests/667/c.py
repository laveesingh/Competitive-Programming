

def solve(a):
	rights = list(a[5:])
	ans = 0
	subs = set()
	while len(rights) >= 2:
		if len(rights) == 2 or len(rights) == 3:
			subs.add(''.join(rights))
			ans += 1
			break
		elif len(rights) == 4:
			if not(rights[-1] == rights[-3] and rights[-2] == rights[-4]):
				subs.add(''.join(rights[:2]))
				subs.add(''.join(rights[2:]))
				subs.add(''.join(rights[1:]))
				ans += 3
				del rights[-1]
				del rights[-1]
				del rights[-1]
		elif len(rights) == 5:
			ans += 4
			subs.add(''.join(rights[-2:]))
			subs.add(''.join(rights[-4:-2]))
			subs.add(''.join(rights[-3:]))
			subs.add(''.join(rights[-5:-2]))
			del rights[-1]
			del rights[-1]
			del rights[-1]
			del rights[-1]
			


		else:
			flag = 0
			if rights[-1] != rights[-3] or rights[-2] != rights[-4]:
				subs.add(''.join(rights[-2:]))
				ans += 1
				flag = 1

			if len(rights) >= 6 and (rights[-1] != rights[-4] or rights[-2] != rights[-5] or rights[-3] != rights[-6]):
				subs.add(''.join(rights[-3:]))
				ans += 1
			del rights[-1]
			del rights[-1]
			if (flag == 0): del rights[-1]

		if len(rights) >= 4 and rights[-2:] == rights[-4:-2]:
			break
		if len(rights) >= 6 and rights[-3:] == rights[-6:-3]:
			break
	return (ans,subs)

a = raw_input()
ans, subs = solve(a)
print ans
for s in sorted(subs):
	print s

