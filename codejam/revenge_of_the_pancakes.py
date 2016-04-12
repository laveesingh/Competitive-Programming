from collections import deque

a = None
steps = 0

def trim():
	global a
	while a and a[-1] == "+":
		a.pop()

def comp(x):
	if x == "+": return "-"
	return "+"

def flip():
	global a
	global steps
	if a and a[0]=="+":
		a[0]="-"
		steps += 1
		i = 1
		while i < len(a) and a[i]=="+":
			# print "Comes in here"
			a[i] = "-"

	if a:
		steps += 1
		a = [comp(s) for s in a[::-1]]


def solve(b):
	global a
	global steps
	a = list(b)
	steps = 0
	while a:
		# print "Steps:",steps
		# print "cur a::",a
		trim()
		# print "cur a:",a
		flip()
	return steps

inputs  = []

for _ in xrange(input()):
	b = raw_input()
	inputs.append(b)
for i, b in enumerate(inputs):
	print "Case #%d:"%(i+1),solve(b)