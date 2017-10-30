I = lambda : map(int, raw_input().split())

n, d = I()
a, b = I()
clients = []
for i in xrange(n):
    clients.append(I())
for i in xrange(n):
    clients[i] = (clients[i][0]*a + clients[i][1]*b, i)
clients.sort()
ans = []
for i in xrange(n):
    if d - clients[i][0] >= 0:
        d -= clients[i][0]
        ans.append(clients[i][1])
print len(ans)
for s in ans:
    print s+1,
print
