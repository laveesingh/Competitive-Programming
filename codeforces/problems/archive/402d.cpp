#include <bits/stdc++.h>

using namespace std;

const long long N = 4e4;
long long isprime[N];
std::vector<long long> primes;
std::set<long long> bads;

void sieve(){
  fill_n(isprime, N, 1);
  isprime[0] = isprime[1] = 1;
  for(long long i = 2; i <= sqrt(N); i++)
    if(isprime[i])
      for(long long j = i*i; j < N; j += i)
        isprime[j] = 0;
  primes.push_back(2);
  for(long long i = 3; i < N; i += 2)
    if(isprime[i])
      primes.push_back(i);
}

inline bool bad(long long prime){
  return bads.find(prime) != bads.end();
}

inline long long f(long long n){
  long long ret = 0;
  for(long long prime: primes){
    long long freq = 0;
    while(n%prime == 0){
      n /= prime;
      freq++;
    }
    if(freq){
      ret += bad(prime) ? -freq : freq;
    }
  }
  if(n>1) ret += bad(n) ? -1 : 1;
  return ret;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  long long n, m;
  cin >> n >> m;
  long long a[n], b[m];
  for(long long i = 0; i < n; i++) cin >> a[i];
  for(long long i = 0; i < m; i++) cin >> b[i];
  bads = set<long long>(b, b+m);
  long long pgcd[n];
  pgcd[0] = a[0];
  for(long long i = 1; i < n; i++) pgcd[i] = __gcd(pgcd[i-1], a[i]);
  long long max_ans = 0, ans = 0;
  for(long long i = 0; i < n; i++)
    ans += f(a[i]);
  max_ans = ans;
  for(long long i = n-1; i >= 0; i--){
    long long cur_f = f(pgcd[i]);
    if(cur_f < 0){
      ans += (-cur_f) * (i+1);
      max_ans = max(ans, max_ans);
      for(long long j = 0; j <= i; j++)
        pgcd[j] /= pgcd[i];
    }
  }
  cout << max_ans << endl;
}

