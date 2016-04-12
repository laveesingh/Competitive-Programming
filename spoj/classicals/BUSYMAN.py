# import operator

# def solve(a):
# 	"a is an array of tuples"
# 	a.sort(key=operator.itemgetter(1))
# 	activities = 1
# 	cur = a[0]
# 	end = cur[1]
# 	for i in xrange(1,len(a)):
# 		cur = a[i]
# 		if cur[0] >= end:
# 			activities += 1
# 			end = cur[1]
# 	return activities

# for _ in xrange(input()):
# 	n = input()
# 	a = []
# 	for __ in xrange(n):
# 		a.append(map(int, raw_input().split()))
# 	print solve(a)

def solve(a, b):
	n = len(a)
	activity = 1


prog = """start = dt()
a.sort(cmp=comp)
print dt()-start"""