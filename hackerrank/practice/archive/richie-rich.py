'''input
6 3
092282
'''

def ispal(a):
	return a == a[::-1]

I = lambda : map(int, raw_input().split())
n, k = I()
a = list(raw_input())
a = [s for s in a if s]
mod = [0]*n
for i in xrange((n+1)/2):
	if k < 1: break
	j = n-i-1
	if a[i] == a[j]:
		None
	else:
		if a[i] < a[j]:
			a[i] = a[j]
			mod[i] = 1
			k -= 1
		else:
			a[j] = a[i]
			mod[j] = 1
			k -= 1
# print ''.join(a), k
if k >= 1:
	for i in xrange((n+1)/2):
		if k < 1: break
		j = n-i-1
		if a[i] == '9':
			None
		else:
			if mod[i] or mod[j]:
				a[i] = '9'
				a[j] = '9'
				k -= 1
			elif k >= 2:
				a[i] = '9'
				a[j] = '9'
				k -= 2

if k > 0 and n%2:
	a[n/2] = '9'

a = ''.join(a)

print a if ispal(a) else -1
			