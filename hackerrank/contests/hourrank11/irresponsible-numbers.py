import re
x, n = map(int, raw_input().split())

xs = str(x)
xs *= n
x = int(xs)
# print "x:",x
def isirr(a):
	a = str(a)
	if set(a)&set('5678'): return 1
	if re.search('9[0-8]', a):
		return 1
	return 0


cnt = 0
irr = []
for i in xrange(1,x+1):
	if(isirr(i)):
		# irr.append(i)
		cnt += 1

print cnt

# while 1:
# 	n = input("Enter a number")
# 	if isirr(n):
# 		print "YES"
# 	else:
# 		print "NO"