n = None
k = None
a = None


def ispossible(i, j):
	global a, n, k
	if a[i][j] != '.': 
		return False
	ii = i
	jj = j
	count = 1
	while ii > 0 and jj > 0:
		ii -= 1
		jj -= 1
		if a[ii][jj] == 'X':
			count += 1
		else:
			break
		
	ii = i
	jj = j
	while ii < n-1 and jj < n-1:
		ii += 1
		jj += 1
		if a[ii][jj] == 'X':
			count += 1
		else: break
		
	if count >= k: 
		#print i, j, "in first attempt"
		return True

	count = 1
	ii = i
	jj = j
	while ii > 0 and jj < n-1:
		ii -= 1
		jj += 1
		if a[ii][jj] == 'X':
			#print "Going up count is",count,"ii is",ii,"jj is",jj
			count+=1
		else: break
		
	ii = i
	jj = j
	while ii < n-1 and jj > 0:
		ii += 1
		jj -= 1
		if a[ii][jj] == 'X':
			#print "Going down count is",count,"ii is",ii,"jj is",jj
			count += 1
		else: break
	#print "In the / diagonally count is", count
	if count >= k: 
		#print i, j, "in second attempt"
		return True

	count = 1
	ii = i
	jj = j
	while ii > 0:
		ii -= 1
		if a[ii][jj] == 'X':
			count += 1
		else: break
	ii = i
	while ii < n-1:
		ii += 1
		if a[ii][jj] == 'X':
			count += 1
		else: break
	if count >= k: 
		#print i, j, "in third attempt"
		return True

	count = 1
	ii = i
	jj = j
	while jj>0:
		jj -= 1
		if a[ii][jj] == 'X':
			count += 1
		else: break

	jj = j
	while jj < n-1:
		jj += 1
		if a[ii][jj] == 'X':
			count += 1
		else: break
	if count >= k: 
		#print i, j, "in fourth attempt"
		return True
	return False


def solve():
	global a, n, k
	flag = 0
	for i in xrange(n):
		for j in xrange(n):
			if ispossible(i,j):
				flag = 1
				break
		if flag == 1:
			break
	print "YES" if flag==1 else "NO"

for _ in xrange(input()):
	n, k = map(int, raw_input().split())
	a = []
	for __ in xrange(n):
		a.append(raw_input())
	solve()
