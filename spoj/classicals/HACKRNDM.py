from bisect import bisect_left as bl, bisect_right as br
n, k = map(int, raw_input().split());a=sorted(map(int, raw_input().split()))
print sum([br(a,a[i]+k)-bl(a,a[i]+k) for i in xrange(n)])