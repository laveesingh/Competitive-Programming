import sys

def nextChar():
	ans = ""
	while 1:
		try:
			t = sys.stdin.read(1)
			if t == " " or t == "\n" or t == "\r" or t == "\t":
				if ans:
					return ans
			else:
				ans += t
		except: return 0

a = [[0 for i in xrange(111)] for j in xrange(111)]

for _ in xrange(int(nextChar())):
	m = int(nextChar())
	n = int(nextChar())
	for i in xrange(1, m+1):
		a[i][1:n+1] = map(int, raw_input().split())
		# for j in xrange(1, n+1):
		# 	a[i][j] = int(nextChar())
	for i in xrange(2, m+1):
		for j in xrange(1, n+1):
			a[i][j] += max(a[i-1][j], a[i-1][j-1], a[i-1][j+1])
	print max([a[m][i] for i in xrange(1, n+1)])

