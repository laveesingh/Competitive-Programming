#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

vector<int> primes_upto_sqrt(int n){
	int l = (int) (sqrt(n) + 1.5);	
	int primes[l];
	for (int i = 0; i < l; i += 1){
		primes[i ] = 0;
	}
	primes[0] = 1;
	primes[1] = 1;
	for (int i = 4; i < l ; i += 2){
		primes[i] = 1;
	}
	for (int i = 3; i < (int)(sqrt(l) + 1.5); i += 2){
		if (!primes[i]){
			for (int j = i*i; j < l ; j += i){
				primes[j] = 1;
			}
		}
	}
	vector<int> temp;
	for (int i = 0; i < l; i += 1){
		if (!primes[i]) temp.push_back(i);
	}
	return temp;
}

stringstream output;


void segmented_sieve(int m, int n){
	int primes[n-m];
	for (int i = 0; i < (n-m) ; i += 1){
		primes[i] = 1;
	}
	if (m < 2){
		primes[0 ] = 0;
	}
	vector<int> sqprime = primes_upto_sqrt(n);
	for (int s: sqprime){
		int start = (m / s) * s + s;
		if(m%s == 0){
			start = m;
		}if(s == start){
			start += s;
		}
		for (int i = start; i < n; i += s){
			primes[i-m] = 0;
		}
	}
	for (int i = 0; i < (n-m); i += 1){
		if (primes[i]){
			output << i+m;
			output << "\n";
		}
	}
}

int main(void){
	int t, m, n;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &m, &n);
		//cout << "Scanned test case" << endl;
		segmented_sieve(m, n+1);
		//cout << "Sieved for this test case." << endl;
	}
	string ans = output.str();
	//printf("%s", ans.substr(0, ans.length()-1));
	cout << ans;
}