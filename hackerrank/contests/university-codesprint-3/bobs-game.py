
board = None

def solve():
    n = input()
    board = []
    for i in xrange(n):
        board.append(raw_input())
    dp = [[None for i in xrange(n)] for j in xrange(n)]
    for i in xrange(n):
        for j in xrange(n):
            if board[i][j] == 'X': dp[i][j] = 'X'
            elif i == 0 and j == 0: dp[i][j] = 'L'
            elif i == 0:
                if dp[i][j-1] == 'L': dp[i][j] = 'W'
                else: dp[i][j] = 'L'
            elif j == 0:
                if dp[i-1][j] == 'L': dp[i][j] = 'W'
                else: dp[i][j] = 'L'
            else:
                if dp[i-1][j] == 'L': dp[i][j] = 'W'
                elif dp[i][j-1] == 'L': dp[i][j] = 'W'
                elif dp[i-1][j-1] == 'L': dp[i][j] = 'W'
                else: dp[i][j] = 'L'
    for s in dp:
        print s
    wkings = 0
    possible_moves = 0
    for i in xrange(n):
        for j in xrange(n):
            if board[i][j] == 'K' and dp[i][j] == 'W':
                wkings += 1
                if i-1 > 0 and dp[i-1][j] == 'L':
                    possible_moves += 1
                if j-1 > 0 and dp[i][j-1] == 'L':
                    possible_moves += 1
                if i-1 > 0 and j-1 > 0 and dp[i-1][j-1] == 'L':
                    possible_moves += 1
    if wkings % 2:
        print "WIN", possible_moves
    else:
        print "LOSE"

for _ in xrange(input()):
    solve()
