#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



vector<int> primes_upto_sqrt(int n){
	int l = (int) (sqrt(n)+1);
	int isprimes[l];
	for (int i =0; i < l; i += 1){
		isprimes[i]  = 1;
	}
	isprimes[0] = 0;
	isprimes[1] = 0;
	for (int i = 4; i < l; i += 2){
		isprimes[i] = 0;
	}
	for (int i = 3; i*i < l ; i += 2){
		if (isprimes[i]){
			for (int j = i*i; j < l ; j += i){
				isprimes[j] = 0;
			}
		}
	}
	vector<int> temp;
	for (int i = 0; i < l; i += 1){
		if (isprimes[i]) temp.push_back(i);
	}
	return temp;

}

void segmented_sieve(int m, int n){
	//cout << "The function called!" << endl;;
	int range = n-m;
	int start;
	int primes[range];
	for (int i = 0; i < n; i += 1){
		primes[i] = 1;
	}
	
	if (m < 2) primes[0] = 0;
	// cout << " The primes array set to 1." ;
	// for (int i = 0; i < n; i += 1) cout << primes[i] << " ";
	// cout << endl;

	vector<int> sqprime = primes_upto_sqrt(n);
	//cout << "vector sqprime: ";
	//for (int x: sqprime) cout << x << " ";
	//cout << endl;
	for (int s: sqprime){
		start = (m/s) * s + s;
		if (m%s == 0) start = m;
		if (s == start) start += s;
		for (int i = start; i < n; i += s) primes[i-m] = 0;
	}
	
	for (int i = 0; i < range; i += 1){
		if (primes[i]) cout << i+m << endl;
	}



}

int main(void){
	int t;
	int n,m;
	cin >> t;
	string ans = "";
	while(t-- > 1){
		cin >> m >> n;
		segmented_sieve(m, n+1);
		cout << endl;
	}
	cin >> m >> n;
	segmented_sieve(m, n+1);
	
}