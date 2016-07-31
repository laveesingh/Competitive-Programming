from fractions import gcd
from itertools import combinations, permutations
a = '123456789'

print "No number is divisible by 9 of the digits"
count = 0
for comb in combinations(a, 8):
	for p in permutations(comb):
		x = int(''.join(p))
		div = sorted(set(map(int,p)), reverse=1)
		divisor = 9*8*7*5
		if 9 not in div:
			divisor /= 3
		elif 8 not in div:
			divisor /= 2
		if x%divisor == 0:
			print x, divisor
			count += 1
print "divisible by 8 is: ", count


