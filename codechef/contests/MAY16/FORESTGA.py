
I = lambda : map(int,raw_input().split())

n, w, l = I()

h = []
r = []
for i in xrange(n):
	x, y = I()
	h.append(x)
	r.append(y)

def fits(n, w, l, mid):
	ans = 0
	for i in xrange(n):
		if h[i] + r[i]*mid > l:
			ans += h[i]+r[i]*mid
	if ans >= w: return 1
	return -1

for i in xrange(10**6):
	if fits(n, w, l, i) == 1:
		print i 
		break

else:
	print "Out of range."
	

# def case():
# 	n = random.randint(1,300)
# 	w = random.randint(1,10**10)
# 	l = random.randint(1,10**10)
# 	print n, w, l
# 	for i in xrange(n):
# 		print random.randint(1,10**6), random.randint(1,10**6)