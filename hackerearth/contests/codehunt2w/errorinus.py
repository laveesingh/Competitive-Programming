

def reverse( a):
	a = int(a)
	a  = int(str(a)[::-1])
	return a


def solve(p, e):
	e = e/100.0
	errored_price = int(p + (p*e))
	# print "errored price ", errored_price
	normal_price = reverse(errored_price)
	# print "normal errored_price", normal_price
	profit = 1-(normal_price/float(p))
	# print "profit", profit
	q = errored_price + (profit*errored_price)
	# print "q", q
	return int(round(q))

t = int(raw_input())
for _ in xrange(t):
	a, b = map(int, raw_input().split())
	print solve(a,b)