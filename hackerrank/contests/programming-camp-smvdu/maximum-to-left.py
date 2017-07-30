from collections import deque

I = lambda : map(int, raw_input().split())

n, q, k = I()
a = I()
st = deque()
for i in xrange(k-1):
    while st and a[st[-1]] <= a[i]: st.pop()
    st.append(i)
ans = [0] * n
for i in xrange(k-1, n):
    if st and i-st[0] >= k: st.popleft()
    while st and a[st[-1]] <= a[i]: st.pop()
    if not st: ans[i] = i
    else: ans[i] = st[0]
    st.append(i)
for _ in xrange(q): print a[ans[int(raw_input())-1]]
