#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int isprime[200001];
vector<int> primes;


void sieve(){
	fill_n(isprime, 200001, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 4; i < 200001; i += 2){
		isprime[i] = 0;
	}
	for (int j = 3; j < 501; j += 2){
		if (isprime[j]){
			for (int k = j*j; k < 200001; k += 2*j){
				isprime[k] = 0;
			}
		}
	}
	primes.push_back(2);
	for (int i = 3; i < 200001; i += 2){
		if(isprime[i]){
			primes.push_back(i);
		}
	}
	return;
}



int main(void){
	int t;
	sieve();
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << primes[n-1] << endl;
	}
}