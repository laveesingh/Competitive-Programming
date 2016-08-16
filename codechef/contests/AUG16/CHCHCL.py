'''input
5
1 1
1 2
1 3
2 2
2 3
'''

for _ in xrange(input()):
	cuts = reduce(lambda x, y: int(x)*int(y), raw_input().split()) -1
	if cuts%2:
		print "Yes"
	else:
		print "No"