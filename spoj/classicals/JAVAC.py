import sys

def isCap(a):
	for s in a:
		if s.isupper():
			return True
	return False

def sp(a):
	if a[0].isdigit():
		return True
	if a[0] == "_" or a[-1] == "_":
		return True
	for i in xrange(len(a)):
		if not (a[i].isalpha() or a[i].isdigit() or a[i] == "_"):
			return True
	return False

def isError(a):
	if sp(a):return True
	if a[0].isupper():
		return True
	for i in xrange(1, len(a)-1):
		if a[i] == "_" and a[i-1] == "_":
			return True
	if "_" in a and isCap(a):
		return True
	return False

def isAgree(a):
	if not("_" in a) and not isCap(a):
		return True
	return False

def isC(a):
	return "_" in a

def isJava(a):
	return isCap(a)

def convert_to_c(a):
	a = list(a)
	toinsert = []
	for i in xrange(len(a)):
		if a[i].isupper():
			toinsert.append(i)
			a[i] = a[i].lower()
	inc = 0
	for s in toinsert:
		a.insert(s+inc, "_")
		inc += 1
	return "".join(a)

def convertToJava(a):
	a = list(a)
	for i in xrange(len(a)):
		if a[i] == "_":
			a[i]  = ""
			if i + 1 < len(a):
				a[i+1] = a[i+1].upper()
	return "".join(a)


def solve(a):
	if isError(a):
		print "Error!"
	elif isAgree(a):
		print a
	elif isC(a):
		print convertToJava(a)
	else:
		print convert_to_c(a)

while 1:
	try:
		a = sys.stdin.readline().strip()
		solve(a)

	except:
		break