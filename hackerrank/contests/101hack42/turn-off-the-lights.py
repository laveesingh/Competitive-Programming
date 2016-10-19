ai = lambda : [int(s) for s in input().split()]
n, k = ai()
c = ai()
bulbs = [1]*n

flip = lambda x: (x+1)%2
mincost = 10**20
for i in range(1,2**n):
	mask = bin(i)[2:].zfill(n)
	inds = [i for i in range(n) if mask[i]=='1']
	nbulbs = bulbs[:]
	for index in inds:
		nbulbs[index] = flip(nbulbs[index])
		p = 1
		while p <= k and index-p >= 0:
			nbulbs[index-p] = flip(nbulbs[index-p])
			p += 1
		p = 1
		while p <= k and index+p < n:
			nbulbs[index+p] = flip(nbulbs[index+p])
			p += 1
	if all([s==0 for s in nbulbs]):
		cost = sum(c[index] for index in inds)
		mincost = min(mincost, cost)
print (mincost)

