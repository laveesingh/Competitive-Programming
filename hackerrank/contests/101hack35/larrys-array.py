a = []

def cycle(n):
	global a
	#print "Cycle:",
	ind = a.index(n)
	#print "Current index:",ind,
	if ind == n-1:
		return
	if ind == len(a)-1:
		temp = ind -1
		a[temp-1], a[temp], a[temp+1] = a[temp], a[temp+1], a[temp-1]
	ind = a.index(n)
	m = a[ind+1]
	#print "next value:",m,
	del a[ind]
	del a[ind]
	
	a.insert(n-1, n)
	a.insert(n, m)

for _ in xrange(input()):
	n = input()
	a = map(int, raw_input().split())
	for i in xrange(1,n):
		cycle(i)
		#print "i: ", i, "a: " , a
	#print a
	if a == range(1, n+1):
		print "YES"
	else:
		print "NO"