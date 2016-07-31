import sys
a = raw_input()

if set(a) == set('0.e'):
	print 0
	sys.exit(0)

a = a.split('e')

expo = int(a[1])

ad = a[0]

ad = ad + ("0"*100)

# print "after adding zeroes ad: ", ad

ind = ad.index('.')
ad = [s for s in ad if s != '.']

# print "ad as list", ad

ad.insert(ind+expo, '.')

# print "after inserting ., ad", ad

ad = ''.join(ad)

# print ad

flag = set(ad.split('.')[1]) == set('0')

if flag:
	# print "First flag"
	ans = ad.split('.')[0]
else:
	j = len(ad)-1
	while(ad[j] == '0'):
		j -= 1
	ans = ad[:j+1]
i = 0
while ans[i] == '0':
	i += 1
ans = ans[i:]
if ans[0] == '.':
	print '0'+ans
else:
	print ans
