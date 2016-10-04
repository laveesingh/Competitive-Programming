#include <bits/stdc++.h>

using namespace std;

int isprime[1001];

void sieve(){
	fill_n(isprime, 1001, 1);
	isprime[0] = 0;
	isprime[1] = 0;
	for(int i = 4; i < 1001; i += 2){
		isprime[i] = 0;
	}
	for(int i = 3; i < 33; i += 2){
		if (isprime[i]){
			for(int j = i*i; j < 1001; j += i){
				isprime[j] = 0;
			}
		}
	}
}


int main(void){
	int n;
	cin >> n;
	sieve();
	vector<int> primes;
	for(int i = 2; i <= n; i += 1){
		if (isprime[i]) primes.push_back(i);
	}
	vector<int> poss;
	for(int prime: primes){
		int temp = prime;
		while(temp <= n){
			poss.push_back(temp);
			temp *= prime;
		}
	}
	cout << poss.size() << endl;
	for(int s: poss) cout << s << " ";
	cout << endl;
}
