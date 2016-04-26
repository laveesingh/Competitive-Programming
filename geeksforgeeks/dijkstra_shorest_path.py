from collections import defaultdict
from pprint import pprint

n, m = map(int, raw_input("Enter the no. of nodes and edges: ").split())
print "Enter the graph now: "

graph = defaultdict(list)
distances = defaultdict(int)

for _ in xrange(m):
	x, y, d = map(int, raw_input().split())
	graph[x].append(y)
	graph[y].append(x)
	distances[(x,y)] = d
	distances[(y,x)] = d

print "The graph is : "
pprint(dict(graph))

print "The weights of the graph is : "
pprint(dict(distances))


# Test Case
# 9 14
# 0 1 4
# 0 7 8
# 1 2 8
# 1 7 11
# 2 3 7
# 2 8 2
# 7 8 7 
# 7 6 1
# 6 8 6
# 2 5 4
# 5 6 2
# 3 5 14
# 3 4 9
# 4 5 10