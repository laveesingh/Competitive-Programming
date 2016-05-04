n = input()
a = map(int, raw_input().split())
mx = max(a)
imx = a.index(mx)
del a[imx]
print mx - sum(a) + 1