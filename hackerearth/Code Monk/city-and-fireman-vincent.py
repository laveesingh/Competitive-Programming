from collections import defaultdict

graph = defaultdict(list)

n = input()
mins = map(int, raw_input().split())

k = input()
for i in xrange(k):
	x, y = map(int, raw_input().split())
	x -= 1
	y -= 1
	graph[x].append(y)
	graph[y].append(x)

visited = [0]*n

final_mins = []

for i in xrange(n):
	if not visited[i]:
		visited[i] = 1
		minimum = mins[i]
		nummin = 1
		stack = [i]
		while stack:
			cur = stack.pop()
			for child in graph[cur]:
				if not visited[child]:
					stack.append(child)
					visited[child] = 1
					if mins[child] < minimum:
						minimum = mins[child]
						nummin = 1
					elif mins[child] == minimum:
						nummin += 1
		final_mins.append(nummin)

# print final_mins
print reduce(long.__mul__, [long(s) for s in final_mins])%(10**9+7)