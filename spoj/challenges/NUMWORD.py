T,S,N,s,E='teen','seven','nine','six','eight'
U=['one','two','three','four','five',s,S,E,N]
D=['ten','eleven','twelve','thir'+T,'four'+T,'fif'+T,s+T,S+T,'eigh'+T,N+T]
X=['twenty','thirty','forty','fifty',s+'ty',S+'ty',E+'y',N+'ty']
def F(n):
 if n==0:return 0
 if 9<n<20:return D[n-10]
 R,r=n/10,""
 if R:r+=X[R-2]+" "
 if n%10:r+=U[n%10-1]
 return r
def W(n):
 if n==0:return"zero"
 r,x="",F(n/1000) 
 if x:r+=x+" thousand "
 n%=1000
 x=F(n/100)
 if x:r+=x+" hundred "
 x=F(n%100)
 if x:r+=x
 r=r.replace("  "," ")
 return r.strip()
print W(input())
