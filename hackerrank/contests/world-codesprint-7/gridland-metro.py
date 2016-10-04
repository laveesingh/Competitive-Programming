from collections import defaultdict as dd

ai = lambda : map(int, raw_input().split())
n, m, k = ai()
store = dd(list)

for _ in xrange(k):
	r, c1, c2 = ai()
	if r <= n and 1 <= c1 <= c2 <= m:
		store[r].append((c1,c2))

ans = 0

for s in store:
	a = store[s]
	a.sort()
	# print a
	ans += a[0][1]-a[0][0] + 1
	# print "Initial ans: ",ans
	last_en =a[0][1]
	for i in xrange(1,len(a)):
		if last_en >= a[i][0]:
			temp = a[i][1] - last_en
			# print "temp:",temp,
			if temp > 0:
				ans += temp
		else:
			ans += a[i][1] - a[i][0] + 1
		# print "ans:",ans
		last_en = max(last_en, a[i][1])
print (n*m - ans)

