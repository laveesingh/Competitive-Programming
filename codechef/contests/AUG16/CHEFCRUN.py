'''input
1
6
-10 -49 73 -67 -7 51
4 6

'''

dist = {}
n = None

def nex(i):
	return (i+1)%n

def prev(i):
	return (i-1+n)%n;

def pay(i, j):
	if dist.get((i,j)): return dist[(i,j)]
	return dist[(j,i)]

def solve(start, end):
	ans, cost, cost2 = 0, 0, 0
	j, i = 0, start
	while (i != end):
		ans += pay(i, nex(i))
		i = nex(i)
	i = start
	cost = ans
	cost2 = ans
	j = end
	while (j != prev(i)):
		cost2 += 2*pay(j, nex(j))
		ans = min(cost2, ans)
		j = nex(j)

	j = end
	dp = {}
	dpd = {}
	dp[(end,end)] = 0
	dpd[(end, end)] = 0
	while j != prev(i):
		dpd[(end, nex(j))] = dpd[(end, j)] + 2*pay(j, nex(j))
		dp[(end, nex(j))] = min(dp[(end, j)], dpd[(end,nex(j))])
		j = nex(j)
	while i != end:
		cost += 2*pay(i, prev(i))
		ans = min(cost, ans)
		cost2 = cost
		cost2 += dp[(end,prev(i))]
		ans = min(cost2, ans)
		# j = end
		# while j != prev(i):
		# 	cost2 += 2*pay(j, nex(j))
		# 	ans = min(cost2, ans)
		# 	j = nex(j)
		i = prev(i)
	return ans

t = int(raw_input())

for _ in xrange(t):
	dist.clear()
	n = int(raw_input())
	a = map(int, raw_input().split())
	for i in xrange(n):
		dist[(i,nex(i))] = a[i]
	st, en = map(int, raw_input().split())
	st -= 1
	en -= 1
	print min(solve(st, en), solve(en, st))