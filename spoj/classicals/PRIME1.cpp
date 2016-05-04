#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> sieve(int n){
	int isprime[n+1]={1};
	// memset(isprime, 10, n);
	fill_n(isprime, n+1, 1);
	// for (int x: isprime) cout << x << endl;
	vector<int> primes;
	if (n >= 2)primes.push_back(2);

	for (int i = 3; i < (int)sqrt(n)+1; i += 2){
		if (isprime[i]){
			// cout << i << endl;
			for (int j = i*i; j <= n; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
	for (int i = 3; i <= n; i += 2){
		if (isprime[i]){
			primes.push_back(i);
		}
	}
	return primes;
}

void Print(vector<int> a){
	cout << "vector : ";
	for (int x : a){
		cout << x << " " ;
	}
	cout << endl;
}

void segmented_sieve(int a, int b){
	int n = sqrt(b);
	// cout << "n: " << n << endl;
	vector<int> primes = sieve(n);
	// Print(primes);
	int finals[b-a+1];
	fill_n(finals, b-a+1, 1);
	for (int p: primes){
		// cout<< "p: " << p << endl;
		// cout << "How can it enter here?" << endl;
		for (int i = a; i <= b; i += 1){
			if (i % p==0){
				if (i != p){
					finals[i-a] = 0;
				}
				for (int j = i+p; j <= b; j += p){
					finals[j-a] = 0;
				}
				break;
			}
		}
	}
	// int start = a%2 == 1 ? a : a+1;
	if (a <= 1) finals[0] = 0;
	for (int i = a; i <= b; i += 1){
		if(finals[i-a]) cout << i << endl;
	}
	cout << endl;
}

int main(){
	int t, a, b;
	cin >> t;
	while (t--){
		cin >> a >> b;
		segmented_sieve(a, b);
	}
}