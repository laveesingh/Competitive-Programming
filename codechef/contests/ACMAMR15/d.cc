#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 1;
const long long mod = 1e9 + 7;

vector<long long> primes;

long long occ[N];
long long ans[N];
long long a[N];

vector<long long> sieve_of_eratosthenes(long long n){
  long long isprime[n+1];
  for(long long i = 0; i <= n; i++) isprime[i] = 1;
  isprime[0] = isprime[1] = 0;
  for(long long i = 4; i <= n; i += 2) isprime[i] = 0;
  for(long long i = 3; i < sqrt(n+1)+1.5; i += 2)
    if(isprime[i])
      for(long long j = i*i; j <= n; j += 2*i)
        isprime[j] = 0;
  vector<long long> primes;
  primes.push_back(2);
  for(long long i = 3; i <= n; i += 2)
    if(isprime[i]) primes.push_back(i);
  return primes;
}

map<long long,long long> pfact_freq(long long n){
  map<long long,long long>pfacts_freq;
  for(long long prime:primes)
  {
       while(n%prime==0)
       {
         pfacts_freq[prime] += 1;
         n=n/prime;
       }
  }
  return pfacts_freq;
}

long long pow(long long a, long long b, long long mod){
	if(b == 0) return 1;
	if(b == 1) return a%mod;
	if(b%2){
		return a*pow(a, b-1, mod) % mod;
	}
	long long x = pow(a, b/2, mod);
	return x*x % mod;
}

int main(void){
	long long t;
	cin >> t;
	primes = sieve_of_eratosthenes(N);
	while(t--){
		long long n;
		cin >> n;
		for(long long i = 0; i < N; i++){
			occ[i] = 0;
			ans[i] = 0;
		}
		for(long long i = 0; i < n; i++){
			cin >> a[i];
		}
		for(long long i = 0; i < n; i++){
			map<long long, long long> facts = pfact_freq(a[i]);
			for(auto it = facts.begin(); it != facts.end(); it++){
				long long cur = it->first;
				for(long long j = 0; j < it->second, cur < N; j++){
					// cerr << "prime: " << it->first << " cur: " << cur << endl;
					occ[cur]++, cur = cur*cur;
				}
			}
		}
		// cerr << "occurrences counted: ";
		// for(long long i = 0; i < 15; i++)
		// 	cerr << i << ": " << occ[i] << endl;
		for(long long prime: primes){
			long long cur = prime;
			while(cur < N){
				ans[cur] = pow(2, occ[cur], mod) - 1;
				if(cur/prime > 1){
					ans[cur/prime] = (ans[cur/prime] - ans[cur] + mod) % mod;
				}
				cur *= prime;
			}
		}
		// cerr << "answers calculated" << endl;
		// for(long long i = 0; i < 15; i++)
		// 	cerr << i << ": " << ans[i] << endl;
		long long final_ans = 1;
		for(long long i = 2; i < N; i++){
			if(ans[i])
				final_ans = (final_ans * pow(i, ans[i], mod)) % mod;
		}
		cout << final_ans << endl;
	}	
}