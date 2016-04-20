
I = lambda : map(int,raw_input().split())

n, k = I()
a = I()

i = 1
rp = a[i-1]
lp = 0
ch = 1
ans = 0

while True:
	cpr = range(lp+1, min(lp+rp, lp+k)+1)
	# print "chapter:",ch,"page no.",i,"cur range:",cpr, "remaining problems:",rp
	if i in cpr:
		ans += 1
	if rp <= k:
		ch += 1
		i += 1
		lp = 0
		rp = a[ch-1] if ch <= n else 0
	else:
		i += 1
		lp += k
		rp -= k
	if ch >= n and rp == 0:
		break

print ans