#include <set>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// the sq must be prime I suppose: FIX THIS

bool primes[1000001];

void setPrimes(){
	// for (long long i = 0; i < 1000001; i += 1){
	// 	primes[i] = 1;
	// }
	memset(primes, 1, 1000001);
	primes[1] = primes[0] = false;
	// for (long long i = 4; i < 1000001; i += 2){
	// 	primes[i] = false;
	// }
	for (long long i = 2; i*i <= 1000001; i += 1){
		// cout << i << " " << primes[i] << endl;
		if (primes[i]){
			// cout << "YES" << endl;
			for (long long j = i*i; j < 1000001; j += i){
				primes[j] = false;
			}
		}
	}

}

int main(void){
	setPrimes();
	// for (long long i = 0; i < 100; i += 1){
	// 	cout << i << " " << primes[i] << endl;
	// }
	long long t;
	cin >> t;
	long long n;
	set<long long> store;
	for (long long i = 2ll; i <= 1000001; i += 1){
		if (primes[i]){
			store.insert(i*i);
		}
	}
	while (t--){
		cin >> n;
		// cout << (isT(n) ? "YES" : "NO") << endl;
		if (store.find(n) != store.end()){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
