from copy import deepcopy

def isvalid(i, j):
	if 0 <= i <= 3 and 0 <= j <= 3:
		return True
	return False



def solve(chess, n, m):
#	print "Our chess is"
#	for s in chess: print s
	if(n >= m): return False
	if n % 2:
		odd = False
		for i in xrange(4):
			for j in xrange(4):
				if chess[i][j].islower():
					if chess[i][j] == 'q':
						'''move horizontally'''
						X = [0, 0]
						Y = [-1, 1]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].islower(): break
								if chess[newi][newj] == 'Q': return False
								if chess[newi][newj].isupper(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								odd = odd or solve(newchess, n+1, m)
								if not movefurther: break
						'''move vertically'''
						X = [-1, 1]
						Y = [0, 0]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].islower(): break
								if chess[newi][newj] == 'Q': return False
								if chess[newi][newj].isupper(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								odd = odd or solve(newchess, n+1, m)
								if not movefurther: break
						'''move diagonally'''
						X = [1, 1, -1, -1]
						Y = [1, -1, 1, -1]
						for move in xrange(4):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].islower(): break
								if chess[newi][newj] == 'Q': return False
								if chess[newi][newj].isupper(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								odd = odd or solve(newchess, n+1, m)
								if not movefurther: break
					if chess[i][j] == 'r':
						'''move horizontally'''
						X = [0, 0]
						Y = [-1, 1]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].islower(): break
								if chess[newi][newj] == 'Q': return False
								if chess[newi][newj].isupper(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								odd = odd or solve(newchess, n+1, m)
								if not movefurther: break
						'''move vertically'''
						X = [-1, 1]
						Y = [0, 0]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].islower(): break
								if chess[newi][newj] == 'Q': return False
								if chess[newi][newj].isupper(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								odd = odd or solve(newchess, n+1, m)
								if not movefurther: break
					if chess[i][j] == 'b':
						'''move diagonally'''
						X = [1, 1, -1, -1]
						Y = [1, -1, 1, -1]
						for move in xrange(4):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].islower(): break
								if chess[newi][newj] == 'Q': return False
								if chess[newi][newj].isupper(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								odd = odd or solve(newchess, n+1, m)
								if not movefurther: break
					if chess[i][j] == 'n':
						'''move knight moves'''
						X = [2, 2, -2, -2, 1, 1, -1, -1]
						Y = [1, -1, 1, -1, 2, -2, 2, -2]
						for move in xrange(8):
							newi = i + X[move]
							newj = j + Y[move]
							if not isvalid(newi, newj):continue 
							if chess[newi][newj].islower():continue 
							if chess[newi][newj] == 'Q': return False
							newchess = deepcopy(chess)
							newchess[newi][newj] = newchess[i][j]
							newchess[i][j] = '0'
							odd = odd or solve(newchess, n+1, m)
		if odd: return odd
	else:
		even = False
		for i in xrange(4):
			for j in xrange(4):
				if chess[i][j].isupper():
					if chess[i][j] == 'Q':
						'''move horizontally'''
						X = [0, 0]
						Y = [-1, 1]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].isupper(): break
								if chess[newi][newj] == 'q': return True 
								if chess[newi][newj].islower(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								even = even or solve(newchess, n+1, m)
								if not movefurther: break
						'''move vertically'''
						X = [-1, 1]
						Y = [0, 0]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].isupper(): break
								if chess[newi][newj] == 'q': return True 
								if chess[newi][newj].islower(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								even = even or solve(newchess, n+1, m)
								if not movefurther: break
						'''move diagonally'''
						X = [1, 1, -1, -1]
						Y = [1, -1, 1, -1]
						for move in xrange(4):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].isupper(): break
								if chess[newi][newj] == 'q': return True 
								if chess[newi][newj].islower(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								even = even or solve(newchess, n+1, m)
								if not movefurther: break
					if chess[i][j] == 'R':
						'''move horizontally'''
						X = [0, 0]
						Y = [-1, 1]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].isupper(): break
								if chess[newi][newj] == 'q': return True 
								if chess[newi][newj].islower(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								even = even or solve(newchess, n+1, m)
								if not movefurther: break
						'''move vertically'''
						X = [-1, 1]
						Y = [0, 0]
						for move in xrange(2):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].isupper(): break
								if chess[newi][newj] == 'q': return True 
								if chess[newi][newj].islower(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								even = even or solve(newchess, n+1, m)
								if not movefurther: break
					if chess[i][j] == 'B':
						'''move diagonally'''
						
						X = [1, 1, -1, -1]
						Y = [1, -1, 1, -1]
						for move in xrange(4):
							movefurther = True
							for sidemove in xrange(1,4):
								newi = i + X[move]*sidemove	
								newj = j + Y[move]*sidemove
								if not isvalid(newi, newj): break
								if chess[newi][newj].isupper(): break
								if chess[newi][newj] == 'q': return True 
								if chess[newi][newj].islower(): movefurther = False
								newchess = deepcopy(chess)
								newchess[newi][newj] = newchess[i][j]
								newchess[i][j] = '0'
								even = even or solve(newchess, n+1, m)
								if not movefurther: break
					if chess[i][j] == 'N':
						'''move knight moves'''
#						print "Knight moves"
						X = [2, 2, -2, -2, 1, 1, -1, -1]
						Y = [1, -1, 1, -1, 2, -2, 2, -2]
						for move in xrange(8):
							newi = i + X[move]
							newj = j + Y[move]
							#print (newi, newj)	
							if not isvalid(newi, newj): continue 
							if chess[newi][newj].isupper():continue 
#							print "Here we are"	
							if chess[newi][newj] == 'q': return True 
							newchess = deepcopy(chess)
							newchess[newi][newj] = newchess[i][j]
							newchess[i][j] = '0'
							even = even or solve(newchess, n+1, m)
		if even : return even
	return False

def Test():
	w, b, m = map(int, raw_input().split())
	chess = [['0' for i in xrange(4)] for j in xrange(4)]
	for white in xrange(w):
		piece, col, row = raw_input().split()
		row = 4 - int(row)
		col = ord(col) - ord('A')
		chess[row][col] = piece
	for black in xrange(b):
		piece, col, row = raw_input().split()
		row = 4 - int(row)
		col = ord(col) - ord('A')
		chess[row][col] = piece.lower()
	print "YES" if solve(chess, 0, m) else "NO"


G = int(raw_input())
for _ in xrange(G):
	Test()	
