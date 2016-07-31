import math

d, h, v, e = map(int, raw_input().split())

r = d/2.0
init_vol = math.pi * r * r * h
inc_vol = math.pi * r * r * e
dec_vol = v

if inc_vol > dec_vol:
	print "NO"
else:
	dtime = 0
	for i in xrange(1,10001):
		init_vol -= dec_vol
		init_vol += inc_vol
		if (init_vol <= 0):
			dtime = i
			break
	if dtime == 0:
		print "NO"
	else:
		init_vol += dec_vol
		init_vol -= inc_vol
		dec_vol /= 1000000.0
		inc_vol /= 1000000.0
		i = dtime - 1.0
		etime = 0.0
		while i <= dtime:
			init_vol -= dec_vol
			init_vol += inc_vol
			if (init_vol <= 0):
				etime = i
				break
			i += 0.000001
		print "YES"
		print etime