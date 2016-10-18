#include<bits/stdc++.h>
using namespace std;
#define I int
#define F(i,n)for(I i=0;i<n;i++)
#define pii pair<I,I>
I Z=1e9,C[8][8],X[]={1,1,-1,-1,2,2,-2,-2},Y[]={2,-2,2,-2,1,-1,1,-1},nx,ny,cf,cs,t,tmp;
bool V(I i,I j){return i>=0&&i<8&&j>=0&&j<8;}
I S(I x,I y,I z,I w){
 if(x==z&&y==w)return 0;
 F(i,8)F(j,8)C[i][j]=Z;
 C[x][y]=0;deque<pii>q;
 q.push_back({x,y});
 while(!q.empty()){
  pii cr=q.front();q.pop_front();cf=cr.first;cs=cr.second;
  F(i,8){
   nx=cf+X[i];ny=cs+Y[i]; 
   if(V(nx,ny)and C[nx][ny]>C[cf][cs]+1)C[nx][ny]=C[cf][cs]+1,q.push_back({nx,ny});
  }
 }
 return C[z][w];
}
map<pair<pii,pii>,int>ST;
I main(void){
 scanf("%d",&t);char a[2],b[2];
 F(i,8)F(j,8)F(k,8)F(l,8)ST[{{i,j},{k,l}}]=S(i,j,k,l);
 while(t--){
  scanf("%s%s",a,b);nx=a[0]-'a';ny=a[1]-'1';cf=b[0]-'a';cs=b[1]-'1';
  printf("%d\n",ST[{{nx,ny},{cf,cs}}]);
 }
} 

