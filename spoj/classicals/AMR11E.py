
def prime_factors(n):
	if not n%2:
		f = [2]
		while not n%2:
			n /= 2
	else:
		f=[]
	i=3
	while i*i <= n:
		if not n%i:
			f.append(i)
			while not n%i:
				n /= i
		i += 2
	if n!=1:f.append(n)
	return f

luckys=[]
for i in xrange(30,3000):
	if len(prime_factors(i)) >= 3:
		luckys.append(i)
		if len(luckys) >= 1000:
			break

for _ in xrange(input()):
	i = input()
	i -= 1
	print luckys[i]