'''input
6
1
17 77 79 46 68 96 62 18 55 18 98 31 63 78 45 34 11 56
56 11 34 45 78 63 31 98 18 55 18 62 96 68 46 79 77
1
14 74 31 90 69 21 39 44 47 40 60 11 96 25 81
81 25 96 11 60 40 47 44 39 21 69 90 31 74
1
3 86 28 92
86 28 92
1
14 72 24 50 36 74 19 85 85 62 21 59 42 16 81
72 24 50 36 74 19 85 85 62 21 59 42 16 81
1
14 28 40 21 34 51 25 52 98 70 27 9 96 49 62
62 49 96 9 27 70 98 52 25 51 34 21 40 28
1
12 5 24 82 32 36 95 76 17 82 56 30 57
5 24 82 32 36 95 76 17 82 56 30 57
'''

def solve(store, final, n, i):
	if i >= len(final):
		return 1
	cur = final[i]
	answers = []
	for j in xrange(n):
		if store[j] and store[j][-1] == cur:
			store[j].pop()
			answers.append(solve(store, final, n, i+1))
			store[j].append(cur)
	if answers and any(answers): return 1
	return 0

for _ in xrange(input()):
	n = input()
	store = [[] for i in xrange(n)]
	for i in xrange(n):
		temp = map(int,raw_input().split())
		store[i] = temp[1:]
	final = map(int, raw_input().split())
	if solve(store, final, n, 0): print "Yes"
	else: print "No"