n = input()
a = map(int, raw_input().split())
a.sort()
if len(a) == 3 and a[0]+a[1] <= a[2]:
	print -1
else:
	x, y, z  = 0, 0, 0
	perimeter = 0
	ans = []
	result = 0
	# print "a:",a
	for i in xrange(len(a)-2):
		for j in xrange(i+1,len(a)-1):
			for k in xrange(j+1,len(a)):
				# print "a[i]:",a[i],"a[j]:",a[j],"a[k]:",a[k]
				if a[i]+a[j] > a[k]:
					ans.append((a[i],a[j],a[k]))
					if perimeter < a[i]+a[j]+a[k]:
						perimeter = a[i]+a[j]+a[k]
	# print "ans",ans
	# print "perimeter",perimeter
	if perimeter == 0: print -1
	else: # to be commented out
		ans = [s for s in ans if sum(s) == perimeter]
		# print "ans:1",ans
		max_third = max(s[2] for s in ans)
		ans = [s for s in ans if s[2] == max_third]
		# print "ans2:",ans
		max_first = max(s[0] for s in ans)
		ans = [s for s in ans if s[0] == max_first]

		x = ans[-1][0]
		y = ans[-1][1]
		z = ans[-1][2]
		print x,y,z


# def case():
# 	n = random.randint(1,10)
# 	print n
# 	for x in xrange(n):
# 		print random.randint(1,5),
# 	print