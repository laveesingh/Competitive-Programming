
# def equal(a,b):
# 	if a >= 0 and b >= 0:
# 		return True
# 	if a < 0 and b < 0:
# 		return True
# 	return False

# def secmin(r, g, b):
# 	if equal(r-g,g-b): return g
# 	if equal(g-r,r-b): return r
# 	return b

# def solve(r, g, b, k):
# 	fmin = min(r, g, b)
# 	smin = secmin(r, g, b)
# 	ans = 0
# 	if fmin < k-1 and smin < k-1:
# 		return fmin*3 + (smin-fmin)*2 + k-smin
# 	if fmin < k-1:
# 		return fmin*3 + 2*(k-fmin-1) + 1
# 	return 3*(k-1) + 1


# for _ in xrange(input()):
# 	a = map(int, raw_input().split())
# 	a.append(input())
# 	print solve(*a)


# def case():
# 	t = random.randint(1,9)
# 	print t
# 	for i in xrange(t):
# 		for j in xrange(3):
# 				print random.randint(1,9),
# 		print
# 		print random.randint(1,9)

def solve(r, g, b, k):
	a = [r, g, b]
	r = min(a)
	b = max(a)
	g = sum(a) - (min(a) + max(a))
	if r >= k-1:
		return 3*(k-1)+1
	if g >= k-1:
		return 3*r + (k-r-1)*2 + 1
	return r+g+k

for _ in xrange(input()):
	r, g, b = map(int, raw_input().split())
	k = input()
	print solve(r, g, b, k)