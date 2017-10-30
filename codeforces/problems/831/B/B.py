from collections import defaultdict

f = defaultdict(str)

a = raw_input()
b = raw_input()
c = raw_input()
for i in xrange(len(a)):
    f[a[i]] = b[i]
cl = c.lower()
d = []
for s in cl:
    if s.isalpha():
        d.append(f[s])
    else:
        d.append(s)
for i in xrange(len(cl)):
    if c[i].isupper():
        d[i] = d[i].upper()
print ''.join(d)
