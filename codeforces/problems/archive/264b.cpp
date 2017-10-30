#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
int isprime[N];
vector<int> primes;
vector<int> inds[N];

void sieve(){
  fill_n(isprime, N, 1);
  isprime[0] = isprime[1] = 0;
  for(int i = 4; i < N; i += 2) isprime[i] = 0;
  for(int i = 3; i <= sqrt(N); i += 2) if(isprime[i])
      for(int j = i*i; j < N; j += 2*i)
        isprime[j] = 0;
  primes.push_back(2);
  for(int i = 3; i < N; i += 2) if(isprime[i])
    primes.push_back(i);
}

vector<int> prime_factors(int n){
  vector<int> ret;
  for(int prime: primes){
    if(prime > n) break;
    if(n%prime == 0){
      ret.push_back(prime);
      while(n%prime == 0) n /= prime;
    }
  }
  return ret;
}


int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
    vector<int> pfs = prime_factors(a[i]);
    for(int pf: pfs)
      inds[pf].push_back(i);
  }
  int dp[n];
  fill_n(dp, n, 0);
  for(int i = n-1; i >= 0; i--){
    //cerr << "DP for " << a[i] << endl;
    vector<int> pfs = prime_factors(a[i]);
    for(int pf: pfs){
      //cerr << "for pf: " << pf << " ";
      int ind = lower_bound(inds[pf].begin(), inds[pf].end(), i) - inds[pf].begin();
      if(ind < inds[pf].size()){
        if(inds[pf][ind] == i and ind+1 < inds[pf].size())
          ind = inds[pf][ind+1];
        else
          ind = inds[pf][ind];
        //cerr << "found " << ind << endl;
        dp[i] = max(dp[i], dp[ind]);
      }
    }
    dp[i]++;
    //cerr << "dp: " << dp[i] << endl;
  }
  cout << *max_element(dp, dp+n) << endl;
}

