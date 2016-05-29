from collections import defaultdict, deque

freq = defaultdict(int)
kfreq = defaultdict(int)
klist = defaultdict(list)

I = lambda : map(int,raw_input().split())

n, k = I()
inputl = I()
total = 0
for s in inputl:
	if s%k == 0:
		total += 1
		break

if k%2 == 0:
	for s in inputl:
		if s == k/2:
			total += 1
			break

if k%2:
	a = [s%k for s in inputl if s%k != 0]
else:
	a = [s%k for s in inputl if (s%k != 0 and s != k/2)]

aset = list(set(a))

for s in a:
	freq[s] += 1

for i in xrange(len(aset)):
	for j in xrange(len(aset)):
		if (aset[i]+aset[j])%k == 0:
			klist[aset[i]].append(aset[j])
			kfreq[aset[i]] += freq[aset[j]]
			if i == j:
				kfreq[aset[i]] -= 1

def comp(x, y):
	global kfreq
	if kfreq[x] <= kfreq[y]:
		return -1
	return 0

aset.sort(reverse=True,cmp=comp)
aset = deque(aset)


i = 0
while len(aset) > 1:
	cur = aset.popleft()
	if kfreq[cur] == 0:
		total += freq[cur]
	else:
		for s in klist[cur]:
			kfreq[s] -= freq[cur]
	aset = deque(sorted(aset, reverse=True, cmp=comp))

if len(aset) == 1:
	cur = aset.pop()
	if kfreq[cur] == 0:
		total += freq[cur]

print total