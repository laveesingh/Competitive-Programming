#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef map<ll ,ll >mll ;
typedef vector<int>vi;
const ll inf=LONG_MAX;
const ll SIZE=5000001;
ll isprime[SIZE];
vi primes;
void sieve(){
isprime[0]=isprime[1]=1;
for(ll i=4;i<SIZE;i+=2){
isprime[i]=1;
}
for(ll i=3;i<sqrt(SIZE)+1.5;i+=2){
if(!isprime[i]){
for(ll j=i*i;j<SIZE;j+=2*i){
isprime[j]=1;
}
}
}
primes.push_back(2);
for(ll i=3;i<SIZE;i+=2){
if(!isprime[i])primes.push_back(i);
}
}
ll solve(ll n,ll k){
ll tk=k;ll ans=0;
while(tk<=n){
ans+=n/tk;
tk*=k;
}
return ans;
}
int main(void){
ios::sync_with_stdio(false);
sieve();
ll t;
cin>>t;
ll C=1;
while(t--){
ll n,k;
cin>>n>>k;
mll fact;
ll tk=k;
for(ll prime:primes){
if(tk<2)break;
while(tk%prime==0){
fact[(ll )prime]++;
tk/=prime;
}
}
ll ans=inf;
for(auto it=fact.begin();it!=fact.end();it++){
ll factor=it->first;
ans=min(ans,solve(n,factor)/fact[factor]);
}
cout<<ans<<endl;
}

}

