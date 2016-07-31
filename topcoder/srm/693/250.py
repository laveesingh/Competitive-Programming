class TriangleEasy:
	def __init__(self):
		return 
	def find(self, n, x, y):
		if not x or not y:
			return 3
		indegree = [0]*(n*(n+1))
		not2 = 0
		graph = [[] for i in xrange(n)]
		for i in xrange(len(x)):
			graph[x[i]].append(y[i])
			graph[y[i]].append(x[i])
		for i in xrange(len(x)):
			indegree[x[i]] += 1
			indegree[y[i]] += 1
			if indegree[x[i]] > 1:
				not2 = 1
				break
			if indegree[y[i]] > 1:
				not2 = 1
				break
		if not2 == 0:
			return 2
		for i in xrange(len(x)):
			for node in xrange(n):
				if node != y[i] and node in graph[x[i]] and node != x[i] and node in graph[y[i]]:
					return 0

		return 1


# n = 20
# x = (16,4,15,6,1,0,10,12,7,15,2,4,8,1,10,15,13,10,1,16,3,19,8,7,13,1,15,15,15,5,16,7,5,6,4,18,3,8,6,2,16,8,19,14,17,16,4,6,9,17,4,10,8,12,2,3,18,9,13,17,4,7,10,0,13,11,15,17,11,15,11,19,19,4,10,14,16,6,3,17,1,4,14,9,7,18,10,11,5,0,5,9,9,7,16,12,4,10,17,3)
# y = (17,18,6,16,18,6,11,2,15,10,1,15,17,8,5,9,7,0,0,4,16,1,9,0,9,5,17,14,1,12,14,11,9,18,0,12,11,3,19,14,7,6,3,19,0,1,19,5,11,19,2,13,12,0,6,2,14,16,14,18,5,5,19,3,6,14,12,5,17,3,1,12,7,11,8,8,10,11,13,2,13,13,0,18,2,7,2,12,14,9,3,19,2,8,12,13,8,18,13,18)

# a = TriangleEasy()
# print a.find(n, x, y)