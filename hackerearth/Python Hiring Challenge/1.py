

def solve(a, n, m):
	row_sum = []
	col_sum = []
	for i in xrange(n):
		row_sum.append(sum(a[i]))
	# print "row_sum :",row_sum
	for i in xrange(m):
		col_sum.append(sum([a[j][i] for j in xrange(n)]))
	# print "col_sum:",col_sum
	maxx = 0
	for s in row_sum:
		for t in col_sum:
			x = s^t
			if x > maxx:
				maxx = x
	print maxx

I = lambda : map(int, raw_input().split())

def main():
	n, m = I()
	a = []
	for _ in xrange(n):
		a.append(I())
	solve(a, n, m)

if __name__ == '__main__':
	main()