
def solve(a):
	energy = 0
	for i in xrange(len(a)-1, -1, -1):
		energy = (energy+a[i]+1)/2
	return energy

n=input()
print solve(map(int, raw_input().split()))