#include <bits/stdc++.h>

using namespace std;

#define limit 500

int isprime[limit+1];
int dp[100000+1];
int isnty[100000+1];
vector<int> primes;

void sieve(){
	fill_n(isprime, limit+1, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 4; i <= limit; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i <= sqrt(limit)+1; i += 2){
		if(isprime[i]){
			for (int j = i*i; j <= limit; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
	for (int i = 2; i <= limit; i += 1){
		if(isprime[i]) primes.push_back(i);
	}
	cout << "Initial prims are " << endl;
	for (int i = 0; i < 10; i += 1){
		cout << primes[i] <<  " ";
	}
}

int digits(int n){
	int ans = 0;
	while(n){
		ans++;
		n/=10;
	}
	return ans;
}

bool isnaughty(int n){
	int x = digits(n);
	int cnt = 0;
	for (int prime: primes){
		if(n%prime == 0){
			cnt++;
			while(n%prime==0){
				n /= prime;
			}
		}
	}
	cout << n << " digits= " << x << " prime factors= " << cnt << endl;
	if (cnt == x) return true;
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	sieve();
	int q, a, b;
	cin >> q;
	fill_n(isnty, 100000+1, 0);
	isnty[1] = 1;
	for (int i = 2; i <= 100000; i += 1){
		if(isnaughty(i)){
			isnty[i] = 1;
		}
	}
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= 100000; i += 1){
		if (isnty[i] == 1){
			dp[i] = dp[i-1]+1;
		}else{
			dp[i] = dp[i-1];
		}
	}
	while(q--){
		cin >> a >> b;
		cout << dp[b]-dp[a] << endl;
	}
}