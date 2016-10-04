import re

n = input()
a = raw_input()

b = re.findall("\(.*?\)", a)
for s in b:
	a = a.replace(s, '_')

inw = 0
maxlen = 0
a = a.split('_')
for s in a:
	maxlen = max(maxlen, len(s))

for s in b:
	cur = s[1:-1]
	cur = cur.split("_")
	for t in cur:
		if t: inw += 1

print maxlen, inw
