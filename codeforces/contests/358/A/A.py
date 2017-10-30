n = input()
a = map(int, raw_input().split())
ans = "no"
for i in xrange(n-1):
    for j in xrange(n-1):
        x1, x2 = sorted([a[i], a[i+1]])
        x3, x4 = sorted([a[j], a[j+1]])
        if x1 < x3 < x2 < x4:
            ans = "yes"
print ans
