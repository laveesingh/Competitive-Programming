#include <bits/stdc++.h>

using namespace std;

#define pii pair<long long, long long>
const long long N = 33000;

long long bin_exp(long long b, long long e, long long mod){
  long long ans = 1;
  while(e > 0){
    if(e%2)
      ans = (ans * b) % mod;
    e /= 2;
    b = (b * b) % mod;
  }
  return ans;
}

vector<pii> prime_factors(long long n){
  vector<pii> ret;
  long long d = 2, freq = 0;
  while(d < n && d < N && n > 1){
    if(n % d == 0){
      n /= d;
      freq++;
    }else{
      if(freq) ret.push_back({d, freq});
      freq = 0;
      d++;
    }
  }
  if(n > 1) ret.push_back({n, 1});
  return move(ret);
}

long long Phi(vector<pii> factors){
  long long ans = 1;
  for(pii key: factors){
    if(key.second == 1)
      ans *= key.first - 1;
    else
      ans *=  (long long)(pow(key.first, key.second) - pow(key.first, key.second-1));
  }
  return ans;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long p;
  cin >> p;
  long long phi_p = p-1;
  vector<pii> factors = prime_factors(phi_p);
  vector<long long> powers_to_test;
  for(pii key: factors)
    powers_to_test.push_back(phi_p / key.first);
  long long ans = 0;
  for(long long pivot = 2; pivot < p; pivot++){
    long long is_root = true;
    for(long long power: powers_to_test)
      if(bin_exp(pivot, power, p) == 1){
        is_root = false;
        break;
      }
    if(is_root){
      ans = pivot;
      break;
    }
  }
  long long phi = Phi(factors);
  cout << ans << " " << phi << endl;
}

