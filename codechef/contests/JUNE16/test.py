def query_print(R):
	global f
	k =1
	enjoyment =1
	while i<=n:
		enjoyment =enjoyment*f[i-1]
		enjoyment =enjoyment%1000000007
		i = 1+k*R
		k+=1
	enjoyment =str(enjoyment)
	print enjoyment[0:1], enjoyment


def update(p, F):
	global f
	f[p-1] = F

n =input()
f =map(int, raw_input().split())

queries =input()
for i in xrange(queries):
	query =map(int, raw_input().split())
	if query[0] == 2:
		R =query[1]
		query_print(R)
	else:
		p, F =query[1], query[2]
		update(p, F)