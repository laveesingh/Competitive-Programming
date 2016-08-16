'''input
7
1 0 1 0 0 0 0
0 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 1
0 0 0 0 1 0 1
7
3 3
78 5
42 5
46 1
91 6
48 4
8 3
'''

from collections import defaultdict, OrderedDict
import sys

def Print(a):
	for  i in xrange(len(a)):
		if a[i]==1:
			print i,
	print

intervals = {}

def solve(k, x):
	
	hm = [0]*n
	hm[x] = 1
	phase = []
	phase.append(hm)
	# Print(phase[0])
	for i in xrange(1,k+1):
		nhm = [0]*n
		for j,s in enumerate(hm):
			if s == 1:
				for adj in graph[j]:
					nhm[adj] = 1
		# hm = list(nhm)
		hm = nhm

		# print i,":",phase[i]
		# Print(phase[i])
		for j in xrange(i):
			if j < len(phase) and phase[j] == nhm:
				# print "Found",j,i
				# interval = i-j
				# ind = (k+1)%interval
				# ans = phase[ind+j]
				interval = i-j
				ind = (k-j)%interval
				ans = phase[ind+j]
				intervals[x] = (j,interval)
				return [i for i in xrange(len(ans)) if ans[i]==1]
		phase.append(hm)
		
	return [i for i in xrange(len(hm)) if hm[i]==1]



# Main programs starts here

graph = defaultdict(list)

inputs = sys.stdin.read().split('\n')

# n = int(raw_input())
n = int(inputs[0]);
ii = 1
for i in xrange(n):
	# temp = raw_input().split()
	temp = inputs[ii].split()
	ii+=1
	for j in xrange(n):
		if temp[j] == '1':
			graph[i].append(j)

# m = int(raw_input())
m = int(inputs[ii])
ii += 1
for _ in xrange(m):
	# k, x = map(int, raw_input().split())
	k, x = map(int, inputs[ii].split())
	ii += 1
	x -= 1
	if intervals.get(x):
		# print "Found"
		start, inter = intervals[x]
		ind = inter+start
		ans = solve(ind,x)
	else: 
		ans = solve(k,x)
	# ans = solve(k,x)
	print len(ans)
	if len(ans) == 0:
		print -1
	else:
		for s in ans:
			print s+1,
		print