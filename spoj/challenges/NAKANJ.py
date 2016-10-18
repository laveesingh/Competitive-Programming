from collections import deque as d
X,Y,Z=[1,1,-1,-1,2,2,-2,-2],[2,-2,2,-2,1,-1,1,-1],10**9
V=lambda i,j:8>i>=0<=j<8
def S(x,y,z,w):
 if(x,y)==(z,w):return 0
 C=[[Z]*8for _ in range(8)];C[x][y]=0;q=d();q.append((x,y))
 while q:
  J,K=q.popleft()
  for i in range(8):
   N,M=J+X[i],K+Y[i]
   if V(N,M)and C[N][M]>C[J][K]+1:
   	C[N][M]=C[J][K]+1
	q.append((N,M))
 return C[z][w]
Q={}
for i in range(64):
 for k in range(64):Q[(i/8,i%8,k/8,k%8)]=S(i/8,i%8,k/8,k%8)
for _ in range(input()):
 a,b=raw_input().split()
 i,j,k,l=ord(a[0])-97,int(a[1])-1,ord(b[0])-97,int(b[1])-1
 print Q[(i,j,k,l)]
