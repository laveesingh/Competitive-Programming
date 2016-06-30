a, b, c, d = map(int, raw_input().split())

if b == d:
	print "NO"
else:
	x = float(a-c)/float(d-b)

	if b <= d:
		print "NO"
	elif x%1 == 0 and x > 0:
		# print x
		print "YES"
		# print a+x*b,c+x*d
	else:
		print "NO"

# def case():
# 	a = randint(0,99)
# 	b = randint(1,100)
# 	c = randint(a+1,100)
# 	d = randint(1,100)
# 	print a,b,c,d