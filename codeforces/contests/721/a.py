n = input()
a = raw_input()

ans = []
cur = 0
for i in xrange(len(a)):
	if a[i] == 'B':
		cur += 1
	else:
		if (cur): ans.append(cur)
		cur = 0
if cur: ans.append(cur)

print len(ans)
for s in ans: print s,
print