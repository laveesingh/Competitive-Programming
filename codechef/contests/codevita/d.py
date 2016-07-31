
inp = raw_input()

tomove = inp.split()[1]
a = inp.split()[0]
a = a.split("/")
moves = []
chess = [['0' for t in xrange(8)] for s in xrange(8)]

def encode(i,j,x,y):
	curmove = chr(ord('a')+j)
	curmove += str(8-i)
	curmove += chr(ord('a')+y)
	curmove += str(8-x)
	return curmove

def wenemyat(i,j):
	if chess[i][j].isalpha() and chess[i][j].islower():
		return 1
	return 0

def benemyat(i,j):
	if chess[i][j].isalpha() and chess[i][j].isupper():
		return 1
	return 0

def isvalid(i,j):
	if i >= 0 and i < 8 and j >= 0 and j < 8:
		return 1
	return 0

def empty(i,j):
	if chess[i][j] == '0':
		return 1
	return 0


for i in xrange(len(a)):
	j = 0
	for k in xrange(len(a[i])):
		# print 'current a[i] ', a[i][k], a[i][k].isalpha(), 'j:',j
		if a[i][k].isalpha():
			chess[i][j] = a[i][k]
			j += 1
		else:
			kn = int(a[i][k])
			while kn > 0 and j < 8:
				chess[i][j] = '0'
				j += 1
				kn -= 1

# for s in chess:
# 	print s

if tomove == 'b':
	for i in xrange(1,7):
		for j in xrange(8):
			if chess[i][j] == 'p':
				if isvalid(i+1,j-1) and benemyat(i+1,j-1):
					moves.append(encode(i, j, i+1, j-1))
				if empty(i+1,j):
					moves.append(encode(i,j,i+1,j))
				if isvalid(i+1,j+1) and benemyat(i+1,j+1):
					moves.append(encode(i,j,i+1,j+1))
else:
	for i in xrange(1,7):
		for j in xrange(8):
			if chess[i][j] == 'P':
				if isvalid(i-1,j-1) and wenemyat(i-1,j-1):
					moves.append(encode(i,j,i-1,j-1))
				if empty(i-1,j):
					moves.append(encode(i,j,i-1,j))
				if isvalid(i-1,j+1) and wenemyat(i-1,j+1):
					moves.append(encode(i,j,i-1,j+1))

ans = ', '.join(moves)
print "[%s]"%ans