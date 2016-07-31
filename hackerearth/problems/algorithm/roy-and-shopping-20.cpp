#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int primes[1000001];
vector<int> prime;

void set_primes(){
	fill_n(primes, 1000001, 1);
	primes[0] = 0;
	primes[1] = 0;
	for (int i = 4; i < 1000001; i += 2){
		primes[i] = 0;
	}
	for (int i = 3; i < 1001; i += 2){
		if(primes[i]){
			for (int j = i*i; j < 1000001; j += i){
				primes[j] = 0;
			}
		}
	}
	for (int i = 2; i < 1001; i += 1){
		
		if(primes[i]) {
			// cout << "pushing: " << i << " ";
			prime.push_back(i);
		}
	}
	// cout << endl;
}

int pf(int n){
	// cout << "Finding pf for " << n << endl;
	if(primes[n]) return n;
	for (int i = 0; i < prime.size(); i += 1){
		if(n%prime[i] == 0) return prime[i];
	}
}

int main(void){
	int t, n;
	set_primes();
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", n-pf(n));
	}
}