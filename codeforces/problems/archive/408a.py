I=lambda:map(int,raw_input().split())
n=input()
K=I()
S=[]
for k in K:S.append(I())
print min(sum(s)*5+15*len(s) for s in S)
