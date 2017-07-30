from itertools import combinations
from math import sqrt



def area(a, b, c):
	s = (a+b+c)/2.0
	areasquare = s*(s-a)*(s-b)*(s-c)
	area = sqrt(areasquare)
	return area

def area_sum(a):
	assert len(a)%3 == 0
	return sum([area(*a[i:i+3]) for i in xrange(0,len(a),3)])

def solve():
	n=input()
	a = map(int, raw_input().split())
	if len(a)%3 == 1:
		_max = 0
		