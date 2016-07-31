
def solve(a, b):
	n = len(a)
	a = int(a, 2)
	b = int(b, 2)
	ans = a^b
	ans = bin(ans)[2:].zfill(n)
	return ans

a = raw_input()
b = raw_input()
print solve(a, b)