#include <bits/stdc++.h>

using namespace std;

const int N = 500001;
int isprime[N];
vector<int> primes;
inline void setPrime(){
	primes.reserve(50001);
	primes.push_back(2);
	for(int i = 3; i < sqrt(N); i += 2){
		if(!isprime[i])
			for(int j = i*i; j < N; j += 2*i) isprime[j] = 1;
	}
	for(int i = 3; i < N; i += 2)
		if(!isprime[i]) primes.push_back(i);
}

vector<pair<int, int> > primeFact(int n){
	vector<pair<int, int> > ret;
	for(int prime: primes){
		if(prime > n) break;
		if(n%prime == 0){
			int freq = 0;
			while (n%prime == 0){
				freq += 1;
				n /= prime;
			}
			ret.push_back(make_pair(prime, freq));
		}
	}
	return ret;
}
			
int pow(int a, int b){
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b&1) return a * pow(a, b-1);
	int x = pow(a, b/2);
	return x*x;
}

int main(void){
	ios::sync_with_stdio(false);
	setPrime();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n==2 or (n%2 and !isprime[n])){
			cout << (n==1 ? 0 : 1) << endl;
			continue;
		}
		vector<pair<int, int> > factors = primeFact(n);
		long long ans = 1ll;
		for(pair<int, int> factor: factors){
			int x = factor.first;
			int freq = factor.second;
			ans *= (pow(x, freq+1) - 1) / (x - 1);
		}
		cout << ans-n << endl;
	}
}
