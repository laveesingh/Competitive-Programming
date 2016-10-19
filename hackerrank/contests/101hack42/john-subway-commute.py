a = raw_input()
n = len(a)
ans = -1
if a[-1] == 'E': ans = n-1
elif a[0] == 'E': ans = 0
try:
  if ans == -1:
    ind = a.index("EE")
    ans = ind+1
except:
  if ans == -1:
    ans = a.rindex('E')
print ans
