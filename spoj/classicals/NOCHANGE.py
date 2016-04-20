
def solve(a, x, k):
	for i in xrange(1, k):
		a[i] += a[i-1]
	ans = [0]*(x+1)
	ans[0] = 1
	for i in xrange(1,x+1): ans[i] = 0
	for i in xrange(k):
		for j in xrange(a[i],x+1):
			ans[j] = ans[j] if ans[j] else ans[j-a[i]]
	return ans[x]

a = map(int, raw_input().split())
print "YES" if solve(a[2:], a[0], a[1]) else "NO	"
