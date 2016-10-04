from itertools import product
import string

letters = string.lowercase

ai = lambda : map(int, raw_input().split())

n, m, k = ai()

P = []
for i in xrange(m):
	P.append(ai())
letset = letters[:n]

allwords = product(letset, repeat=m)

def cost(s):
	ans = 0
	for i in xrange(m):
		ans += P[i][ord(s[i])-ord('a')]
	return ans

finset = [(cost(s), ''.join(s)) for s in allwords]
finset.sort(reverse=1)
print finset[k-1][1]
