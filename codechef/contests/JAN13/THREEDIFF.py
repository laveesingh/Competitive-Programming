MOD = 10**9 + 7
for _ in xrange(input()):
	a, b, c = map(int, raw_input#().split())
	a, b, c = sorted([a,b,c])
	print ((a%MOD*(b-1)%MOD)%MOD*(c-2)%MOD)%MOD


# def case():
# 	t =10
# 	print t
# 	for _ in xrange(t):
# 		print randint(10**15,10**18), randint(10**15,10**18),randint(10**15,10**18)