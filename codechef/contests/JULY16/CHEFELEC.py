for _ in xrange(input()):
	n = input()
	vil = raw_input()
	dist = map(int,raw_input().split())
	if n == 1:
		print 0
		continue
	ind = []
	for i in xrange(len(vil)):
		if vil[i] == '1':
			ind.append(i)
	ans = 0
	if ind[0] != 0:
		ans += abs(dist[ind[0]] - dist[0])
	if ind[-1] != n-1:
		ans += abs(dist[ind[-1]] - dist[n-1])
	# print "initial answer", ans
	for i in xrange(len(ind)-1):
		f = ind[i]
		l = ind[i+1]
		if l-f > 1:
			# print "adding",abs(dist[l]-dist[f])
			ans += abs(dist[l]-dist[f])
			tod= max(abs(dist[j]-dist[j+1]) for j in xrange(f,l))
			# print "subtracting", tod
			ans -= tod
	print ans