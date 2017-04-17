#include <iostream>
#include <unordered_map>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

#define umap unordered_map
const long long N = 1e6+1;
long long isprime[N];
vector<long long> primes;
umap<long long, umap<long long, long long> > prime_factors;
umap<long long, long long> remaining;
umap<long long, long long> store;

void print(umap<long long, long long> a){
  for(pair<long long, long long> val: a)
    cerr << val.first << ":" << val.second << ", ";
  cerr << endl;
}

// This function finds total number of divisors of given n, given prime_factors
long long total_divisors(long long n){
  if(n==1) return 0;
  long long total_divs = 1;
  for(pair<long long, long long> key: prime_factors[n])
    total_divs *= (key.second + 1);
  return max(1ll, total_divs-1); // This line may be the culprit
}

// This function sets primes vector and isprime array
void sieve(){
  fill_n(isprime, N, 1);
  isprime[0] = isprime[1] = 0;
  //for(long long i=4; i<N; i+=2){
    //isprime[i] = 0;
  //}
  for(long long i=3; i<sqrt(N)+1; i+=2){
    if (isprime[i]){
      for(long long j=i*i; j<N; j+=2*i){
        isprime[j] = 0;
      }
    }
  }
  primes.push_back(2);
  for(long long i=3; i<N; i+=2)
    if(isprime[i])
      primes.push_back(i);
}

// This function sets prime factors of numbers in range (a,b+1)
void set_prime_factors(long long a, long long b){
  for(long long i = a; i <= b; i += 1)
    remaining[i] = i;
  long long len = b-a+1;
  for(long long prime: primes){
    long long start = (a/prime) * prime; //Or this starting point can be wrong 
    if (start < a)
      start += prime;
    if (start == prime)
      start += prime;
    for(long long i=start; i<=b; i+=prime){
      long long frequency = 0, value = 1;
      while(i % value == 0){
        frequency++;
        value *= prime;
      }
      frequency--;
      value /= prime;
      remaining[i] /= value;
      prime_factors[i][prime] = frequency ;
    }
  }
  for(long long i = a; i <= b; i += 1)
    if(remaining[i] != 1){
      prime_factors[i][remaining[i]] = 1;
    }
}

// This function returns next biggest factor of n along with its prime factors
long long NBF(long long n){
  umap<long long, long long> freq = prime_factors[n];
  long long maxf = 0, maxx = 0;
  for(pair<long long, long long> pfact: freq)
    if(pfact.second > maxf){
      maxf = pfact.second;
      maxx = pfact.first;
    }
  freq[maxx]--;
  long long ret = 1;
  for(pair<long long, long long> pfact: freq)
    for(long long i = 0; i < pfact.second; i++)
      ret *= pfact.first;
  prime_factors[ret] = freq;
  //cerr << "NBF of " << n << " is " << ret << endl;
  //cerr << "prime factors of " << n << " are ";
  //print(prime_factors[n]);
  return ret;
}

long long solve(long long n){
  if(store[n]) return store[n];
  if(n == 1) return 1;
  long long ret = total_divisors(n) + 1;
  return store[n] = ret + solve(NBF(n));
}

int main(void){
  ios::sync_with_stdio(false);
  sieve();
  long long a, b, ans = 0;
  cin >> a >> b;
  set_prime_factors(a, b);
  store[1] = 1;
  for(long long n = a; n <= b; n += 1){
    ans += solve(n)-1;
  }
  cout << ans << endl;
}
