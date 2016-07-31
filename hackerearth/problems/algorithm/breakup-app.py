import re
from collections import defaultdict

n = input()
f = defaultdict(int)
for _ in xrange(n):
	a = raw_input()
	a = a.split(':')
	temp = re.findall('[0-9]+', a[1])
	for date in temp:
		if int(date) > 0 and int(date) < 31:
			f[int(date)] += 2 if a[0]=='G' else 1
# print f
mx = max(f.values()) if f else 0
flag = 0
ans = "Date"
# print "mx:",mx
# print f[19] == mx
# print f[20] == mx
# print f[21] == mx
if f[19] == mx and f[20] == mx:
	print "No Date"
elif f[19] == mx or f[20] == mx:
	print "Date"
else:
	print "No Date"