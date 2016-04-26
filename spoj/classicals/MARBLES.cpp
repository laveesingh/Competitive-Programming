#include <cstdio>

using namespace std;

long long comb(int n, int m){
    if(m>n-m) m=n-m;
    
    long long ans=1;
    
    for(int i=0;i<m;i++) ans=ans*(n-i)/(i+1);
    
    return ans;
}

int main(){
    int t,n,k;
    
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        printf("%lld\n",comb(n-1,k-1));
    }
    
    return 0;
}