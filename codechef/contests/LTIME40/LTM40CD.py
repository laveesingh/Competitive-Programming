r = input()
st = set()
for a in xrange(1,500):
	for b in xrange(1,500):
		for c in xrange(1,500):
			p = float(a+b+c)/2
			area = (p * (p-a) * (p-b) * (p-c)) ** 0.5
			R = area/p
			if abs(r-R) < .000001:
				st.add(sorted([a,b,c]))

for s in st:
	for t in s:
		print t,
	print
