r=lambda:map(int,raw_input().split())
for _ in range(input()):
 n,m=r();a=sorted(r());s=0
 for i in range(m):s+=a[i]if a[i]<0 else 0 
 print -s
