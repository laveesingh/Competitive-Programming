from itertools import permutations

def balanced(a):
	stack = []
	for i in xrange(len(a)):
		if stack and a[i] == '[' and stack[-1] == '(':
			return False
		if a[i] == '(' or a[i] == '[':
			stack.append(a[i])
		elif a[i] == ')':
			if len(stack) == 0: return False
			t = stack.pop()
			if t != '(':
				return False
		elif a[i] == ']':
			if len(stack) == 0: return False
			t = stack.pop()
			if t != '[':
				return False
	return True

def isvalid(a):
	
	if balanced(a):
		return True
	return False
		

t = int(raw_input())
for _ in xrange(t):
	x, y = map(int, raw_input().split())
	a = "[]"*x
	a += "()"*y
	ans = 0
	for s in permutations(a):
		if isvalid(''.join(list(s))):
			# print ''.join(list(s))
			ans += 1
	print ans/(x*y)