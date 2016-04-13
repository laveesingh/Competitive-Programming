
def solve(a, b):
	a.sort(reverse=True)
	b.sort(reverse=True)
	nh, nv = 0, 0
	i, j = 0, 0
	ans = 0
	while i < len(a) or j < len(b):
		h = nh if nh else 1
		v = nv if nv else 1
		if a[i]*h > b[j]*v:
			nh += 1
			ans += b[j]*v
			j += 1
		elif a[i]*h <= b[j]*v:
			nv += 1
			ans += a[i]*h
			i += 1
		h = nh if nh else 1
		v = nv if nv else 1
		if i == len(a):
			while j < len(b):
				nh += 1
				ans += b[j]*v
				j += 1
		if j == len(b):
			while i < len(a):
				nv += 1
				ans += a[i]*h
				i += 1
	return ans

t = input()
I = lambda : map(int, raw_input().split())
x, y = I()
a = I()
b = I()
print solve(a,b)



