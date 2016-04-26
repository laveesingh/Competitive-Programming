from collections import defaultdict

def cycle(cur):
	if cur == "A": return "B"
	if cur == "B": return "C"
	if cur == "C": return "A"

cages = defaultdict(int)
cfrom = defaultdict(int)
t = input()

for i in xrange(1, t+1):
	n = input()
	cages[i] = n
	cfrom[n] = i

chains = []
chained = [0] * (t+1)

for i in xrange(1, t+1):
	if not chained[i]:
		temp = []
		temp.append(i)
		chained[i] = 1
		cur = cages[i]
		while cur != i:
			temp.append(cur)
			chained[cur] = 1
			cur = cages[cur]
		chains.append(temp)

colors = defaultdict(int)
cur = "A"
for chain in chains:
	for s in chain:
		colors[s] = cur
		cur = cycle(cur)
	if (len(chain)-1)%3 == 0:
		colors[chain[-1]] = cur
		cur = cycle(cur)

ans = ""
for i in xrange(1, t+1):
	ans += colors[i]

print ans

