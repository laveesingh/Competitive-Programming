from collections import defaultdict
import sys

class activity:
	def __init__(self, start, end, comp):
		self.start = start
		self.end = end
		self.comp = comp

	def __repr__(self):
		string = "%d %d %d"%(self.start, self.end, self.comp)
		return string

def compare(act1, act2):
	if act1.end == act2.end:
		return -1 if act1.start < act2.start else 0
	return -1 if act1.end < act2.end else 0

def solve(n, k, a):
	ans = 0
	a.sort(compare)
	d = defaultdict(int)
	for act in a:
		start = act.start
		end = act.end
		comp = act.comp
		if d[comp] == 0:
			d[comp] = end
			ans += 1
		else:
			if start >= d[comp]:
				ans += 1
				d[comp] = end
	return ans
inputstring = sys.stdin.read()
inputarray = inputstring.split("\n")
t = int(inputarray[0])
ii = 1
ans = ""
for _ in xrange(t):
	n, k = map(int, inputarray[ii].split())
	ii += 1
	a = []
	for i in xrange(n):
		a.append(activity(*map(int, inputarray[ii].split())))
		ii += 1
	ans += `solve(n, k, a)` +"\n"

sys.stdout.write(ans)