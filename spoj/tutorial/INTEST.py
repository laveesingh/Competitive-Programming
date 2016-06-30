import sys

inputs = sys.stdin.read().split('\n')

n, k = map(int,inputs[0].split())
count = 0
for i in xrange(1,n+1):
	if int(inputs[i]) % k == 0:
		count += 1
print count