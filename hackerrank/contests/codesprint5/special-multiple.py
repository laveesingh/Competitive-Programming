
from collections import defaultdict, deque

mults = defaultdict(int)

a = range(1,501)
mults[1]= 9
mults[3] = 9
mults[9] = 9

q = deque()
q.append('0')
q.append('9')
flag = False
while flag == False:
	cur = q.popleft()
	x = int('9'+cur)
	flag = True
	for s in a:
		if not mults[s] and x%s == 0:
			mults[s] = x
		if not mults[s]:
			flag = False
	q.append(cur+'0')
	q.append(cur+'9')

for _ in xrange(input()):
	n = input()
	print mults[n]


