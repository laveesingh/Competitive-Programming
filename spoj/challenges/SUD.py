from timeit import default_timer as dt
import time, sys, os

import threading


def findNextCellToFill(grid, i, j):
        for x in range(i,9):
                for y in range(j,9):
                        if grid[x][y] == 0:
                                return x,y
        for x in range(0,9):
                for y in range(0,9):
                        if grid[x][y] == 0:
                                return x,y
        return -1,-1

def isValid(grid, i, j, e):
        rowOk = all([e != grid[i][x] for x in range(9)])
        if rowOk:
                columnOk = all([e != grid[x][j] for x in range(9)])
                if columnOk:
                        # finding the top left x,y co-ordinates of the section containing the i,j cell
                        secTopX, secTopY = 3 *(i/3), 3 *(j/3)
                        for x in range(secTopX, secTopX+3):
                                for y in range(secTopY, secTopY+3):
                                        if grid[x][y] == e:
                                                return False
                        return True
        return False

def solveSudoku(grid, i=0, j=0):
        i,j = findNextCellToFill(grid, i, j)
        if i == -1:
                return True
        for e in range(1,10):
                if isValid(grid,i,j,e):
                        grid[i][j] = e
                        if solveSudoku(grid, i, j):
                                return True
                        # Undo the current cell for backtracking
                        grid[i][j] = 0
        return False

def solve(a):
    a = a.replace('.','0')
    a = list(a)
    a = [map(int, a[i:i+9]) for i in xrange(0,81,9)]
    solveSudoku(a)
    print "Y"
    ans = ""
    for s in a:
        for t in s:
            ans += str(t)
    print ans

def main():
    i = 0
    t = input()
    for _ in xrange(t):
        i += 1
        solve(raw_input())
        if i > 2:
            for __ in xrange(t-i):
                print "N"
            return
main()


