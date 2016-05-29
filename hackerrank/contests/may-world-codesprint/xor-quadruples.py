
a, b, c, d = sorted(map(int, raw_input().split()))

total = 0

for i in xrange(1,a+1):
	for j in xrange(i,b+1):
		for k in xrange(j,c+1):
			for l in xrange(k,d+1):
				if (i^j^k^l) != 0:
					total += 1
print total