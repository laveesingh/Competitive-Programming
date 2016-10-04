
def syl(a):
	count = 0
	for s in a:
		if s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u' or s == 'y':
			count += 1
	return count

n = input()
a = map(int, raw_input().split())

ans = "YES"

for i in xrange(n):
	temp = raw_input()
	if syl(temp) != a[i]:
		ans = "NO"
		break

print ans