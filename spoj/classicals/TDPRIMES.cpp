#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

// #define M 86028500
#define M 100000001

int flagArr[M>>6]; // M/64
#define ifComp(x) (flagArr[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (flagArr[x>>6]|=(1<<((x>>1)&31)))

using namespace std;

int main(void){
	vector<int> primes;
	primes.push_back(2);
	int k, count = 0;

	for (int i = 3; i < (int)sqrt(M)+1; i += 2){
		if(!ifComp(i)){
			// count +=1 ;
			// primes.push_back(i);
			for (int j = i*i, k=i<<1; j < M; j += k){
				isComp(j);
			}
		}
	}
	for (int i = 3; i < M; i += 2){
		if(!ifComp(i)){
			primes.push_back(i);
		}
	}
	// for (int i = 0; i < 50; i += 1){
	// 	cout << primes[i] << endl;
	// }
	// cout << "The count is : " << count << " length of the primes vector is: " << primes.size() << endl;

	// int t, n;
	// cin >> t;
	// while (t--){
	// 	cin >> n;
	// 	cout << primes[n-1] << endl;
	// }
	for (int i = 1; i < primes.size(); i += 100){
		cout << primes[i-1] << endl;
	}
}