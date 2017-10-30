I = lambda: map(int, raw_input().split())
n = input()
Adj = [[] for i in xrange(n)]
C = I()
leaves = []
for i in xrange(n-1):
    x, y = I()
    x -= 1
    y -= 1
    Adj[x].append(y)
    Adj[y].append(x)

for i in xrange(n-1):
    if len(Adj[i]) == 1:
        leaves.append(i)

def dfs(source, par):
    if C[source] == 0:
        white[source] += 1
    else:
        black[source] += 1
    for adj in Adj[source]:
        if adj == par: continue
        dfs(adj, source)
        white[source] += white[adj]
        black[source] += black[adj]

max_ans = 0
ans = []
for leaf in leaves:
    white = [0] * n
    blacks = [0] * n
    dfs(leaf, -1)

