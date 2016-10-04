n = input()
a = raw_input()
chars = set(a)

def good(s):
	if len(s) < 2:
		return 0
	f = s[0]
	sec = s[1]
	for i in xrange(len(s)):
		if i%2 and s[i] != sec:
			return 0
		if i%2 == 0 and s[i] != f:
			return 0
	return 1

ans = 0
for s in chars:
	for t in chars:
		if s != t:
			news = [x for x in a if x==s or x == t]
			if good(news):
				ans = max(ans, len(news))
print ans

