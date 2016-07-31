from collections import defaultdict, deque

I = lambda : map(int, raw_input().split())

n = input()

dist = defaultdict(int)
child = defaultdict(list)

for _ in xrange(n-1):
	x, y, z = I()
	dist[(x,y)] = z
	child[x].append(y)
	child[y].append(x)

for i in xrange(2,n+1):
	if(dist[(1,i)] and dist[(i,1)]):
		None
	else:
		for j in xrange(2,n):
			if dist[(i,j)] and dist[(1,j)]:
				dist[(1,i)] = dist[(1,j)] + dist[(i,j)]
				break
			elif dist[(j,i)] and dist[(1,j)]:
				dist[(1,i)] = dist[(1,j)] + dist[(j, i)]
				break
for i in xrange(n+1,1,-1):
	if(dist[(1,i)] and dist[(i,1)]):
		None
	else:
		for j in xrange(2,n):
			if dist[(i,j)] and dist[(1,j)]:
				dist[(1,i)] = dist[(1,j)] + dist[(i,j)]
				break
			elif dist[(j,i)] and dist[(1,j)]:
				dist[(1,i)] = dist[(1,j)] + dist[(j, i)]
				break
ans = 0
for i in xrange(2,n+1):
	ans += dist[(1,i)]
print ans