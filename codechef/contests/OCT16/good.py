n = input()
def good(a):
    cnt2 = a.count('2')
    cnt22 = a.count('2211')
    if a[-1] == '2' and cnt2 == 2*cnt22+1:
        return 1
    if a[-1] != '2' and cnt2 == 2*cnt22:
        return 1
    return 0

for _ in xrange(n):
	a = raw_input()
	print "YES" if good(a) else "NO"

