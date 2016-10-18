
def fact(n):
	two, five = 0, 0
	while n % 2 == 0:
		n /= 2
		two += 1
	while n%5 == 0:
		n /= 5
		five += 1
	return [two, five]

def merge(x, y):
	x[0] += y[0]
	x[1] += y[1]
	'''This function will modify x, instead of returning the result'''

ai = lambda : map(int, raw_input().split())
import sys
inputs = sys.stdin.read().split('\n')
ind = 1 
for _ in xrange(int(inputs[0])):
	n, m = map(int, inputs[ind].split());
	ind+=1
	a = map(int, inputs[ind].split())
	ind += 1
	T = [fact(s) for s in a]
	ans = 0	
	for query in xrange(m):
		Q = map(int, inputs[ind].split()) 
		ind += 1	
		if Q[0] == 1:
			for i in xrange(Q[1]-1, Q[2]):
				merge(T[i], fact(Q[3]))
		elif Q[0] == 2:
			basefact = fact(Q[3])
			iy = 1;
			#print "Basefact:",basefact
			for i in xrange(Q[1]-1, Q[2]):
				T[i] = basefact[:]
				#print T[i],"=>merging:",fact(iy),
				merge(T[i], fact(iy))
				#print "After merging:",T[i]
				iy += 1
		else:
			two = 0
			five = 0
			for i in xrange(Q[1]-1, Q[2]):
				two += T[i][0]
				five += T[i][1]
			ans += min(two, five)
	print ans
