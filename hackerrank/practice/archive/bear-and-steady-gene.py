'''input
40
TGATGCCGTCCCCTCAACTTGAGTGCTCCTAATGCGTTGC
'''

n = input()
a = raw_input()
from collections import defaultdict
f = defaultdict(int)
i, j = 0, n-1
maxf = n/4
movi, movj = 1,1
while (movi or movj) and i < j:
	if movi:
		print "i:",i,"f[",a[i],"]: ", f[a[i]]
		if f[a[i]] == maxf:
			movi = 0
		else:
			f[a[i]] += 1
			i += 1
	if movj:
		print "j:",j,"f[",a[j],"]: ", f[a[j]]
		if f[a[j]] == maxf:
			movj = 0
		else:
			f[a[j]] += 1
			j -= 1
print i,j
print j-i+1