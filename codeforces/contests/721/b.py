n, k = map(int, raw_input().split())

from collections import defaultdict as dd

store = dd(int)

for _ in xrange(n):
	temp = raw_input()
	store[len(temp)] += 1

correct = raw_input()

ans = 0
for i in xrange(1,len(correct)):
	ans += store[i]


best = ans
best = best + (best/k)*5
best += 1

worst = ans + store[len(correct)]-1
worst = worst + (worst/k)*5
worst += 1

# print store
print best, worst