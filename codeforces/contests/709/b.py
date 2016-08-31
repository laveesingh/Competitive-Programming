n, x = map(int, raw_input().split())
a = sorted(map(int, raw_input().split()))
if n == 1: print 0
else: print min(a[n-2]-a[0]+min(abs(x-a[0]),abs(x-a[n-2])), a[n-1]-a[1]+min(abs(x-a[1]),abs(x-a[n-1])))