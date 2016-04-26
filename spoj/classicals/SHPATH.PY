from collections import defaultdict
from pprint import pprint

store = defaultdict(int)
weights = defaultdict(int)

def minDist(graph, a, b):
	temp = store[(a,b)]
	if temp: return temp
	
	return min([minDist(graph, a, s) for s in graph[b]])




for test in xrange(1, input()+1):
	store.clear()
	weights.clear()
	n = input()
	graph = defaultdict(list)
	namecities = defaultdict(int)
	nocities = defaultdict(str)
	for city in xrange(1, n+1):
		name = raw_input()
		namecities[name] = city
		nocities[city] = name
		nngh = input()
		for neigh in xrange(nngh):
			non, weight = map(int, raw_input().split())
			graph[city].append(non)
			# graph[non].append(city)
			weights[(city, non)] = weight
	print minDist(graph, 1, 3)

pprint(graph)
pprint(namecities)
pprint(nocities)
pprint(weights)