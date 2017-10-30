
n = input()
mat = []
for i in xrange(n):
    mat.append(map(int, raw_input().split()))
ans = 0
for i in xrange(n):
    ans = (ans + mat[i][i]) % 2

q = input()

answers = []
for i in xrange(q):
    query = map(int, raw_input().split())
    if query[0] == 3:
        answers.append(str(ans))
    else:
        ans = 1 - ans

print ''.join(answers)
