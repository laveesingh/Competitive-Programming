
def solve(a):
	if len(a) <= 1: return 0
	if len(a) == 2: return a[0]*a[1]
	first = a[:-3] + [(a[-3]+a[-2])%100] + [a[-1]]
	second = a[:-2] + [(a[-2]+a[-1])%100]
	return min(a[-3]*a[-2]+solve(first), a[-2]*a[-1] + solve(second))
import sys

inputs = sys.stdin.read()
inputl = inputs.split('\n')
# print inputl
i = 0
while i < len(inputl):
	if not inputl[i]: break
	n = int(inputl[i])
	i += 1
	a = map(int, inputl[i].split())
	i += 1
	print solve(a)
