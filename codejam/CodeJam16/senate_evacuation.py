import sys

def solve(a):
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	l = len(a)
	mx = max(a)
	plan = []
	while l > 0:
		temp = ""
		if mx == 1 and l == 3:
			i = a.index(1)
			a[i] -= 1
			l -= 1
			temp += alpha[i]
		else:
			i = a.index(mx)
			a[i] -= 1
			temp += alpha[i]
			if a[i] == 0:
				l -= 1
			mx = max(a)
			i = a.index(mx)
			a[i] -= 1
			temp += alpha[i]
			if a[i] == 0:
				l -= 1
			mx = max(a)
		plan.append(temp)
	return plan
inputs = sys.stdin.read().split("\n")
i = 0
t = int(inputs[i])
i+=1
for _ in xrange(t):
	n = int(inputs[i])
	i += 1
	a = map(int, inputs[i].split())
	i += 1
	print "Case #%d:"%(_+1),
	for s in solve(a):
		print s,
	print

