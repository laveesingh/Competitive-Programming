n = input()

b = bin(n)[2:]

x = b.count('0')
if n == 0:
	print 1
else: print 2 ** x