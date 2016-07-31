from collections import defaultdict


def ispal(a):
	return a == a[::-1]

def solve(a, n, k):
	mod = defaultdict(int)
	a = list(a)
	if k == 0: 
		if ispal(a):
			return ''.join(a)
		else:
			return "-1"
	if n%2 == 0:
		i = n/2 - 1
		while i >= 0:
			if k == 0:
				if ispal(a):
					return ''.join(a)
				else:
					return "-1"
			if a[i] != a[n-i-1]:
				if a[i] > a[n-i-1]:
					a[n-i-1]  = a[i]
					mod[n-i-1] = 1
				else:
					a[i] = a[n-i-1]
					mod[i] = 1
				k -= 1
			i -= 1

	else:
		i = n/2
		while i >= 0:
			if k == 0:
				if ispal(a):
					return ''.join(a)
				else:
					return "-1"
			if a[i] != a[n-i-1]:
				if a[i] > a[n-i-1]:
					a[n-i-1] = a[i]
					mod[n-i-1] = 1
				else:
					a[i] = a[n-i-1]
					mod[i] = 1
				k -= 1
			i -= 1
	i = 0
	while k > 0 and i <= (n-1)/2:
		j = n-i-1
		if mod[i] == 1 and mod[j] == 1:
			a[i] = '9'
			a[j] = '9'
		elif mod[i] == 1 or mod[j] == 1:
			if a[i] != '9': k -= 1
			a[i] = '9'
			a[j] = '9'
			# k -= 1
		elif i == j:
			if mod[i] != 1:
				k -= 1
			a[i] = '9'
		elif k >= 2:
			if a[i] != '9': k -= 2
			a[i] = '9'
			a[j] = '9'
			# k -= 2
		i += 1
	return ''.join(a)

n, k = map(int, raw_input().split())
a = raw_input()
print solve(a,n,k)

# t = input()

# inputs  = []
# for i in xrange(t):
# 	n, k = map(int, raw_input().split())
# 	a =raw_input()
# 	inputs.append((a,n,k))

# for s in inputs:
# 	print solve(*s)


# import random
# def case():
# 	n = random.randint(1,9)
# 	k = random.randint(1,6)
# 	print n,k,
# 	a = ""
# 	for i in xrange(n):
# 		a += str(random.randint(1,9))
# 	print a
# 	return (n,k,a)

# for i in xrange(10):
# 	print "%d: ",(i+1)
# 	n, k, a = case()
# 	print solve(a,n,k)
