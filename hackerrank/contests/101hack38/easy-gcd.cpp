#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	// cout << "Finding gcd for " << a << " and " << b << endl;
	if(b == 0) return a;
	// cout << "B = " << b << endl;
	return gcd(b, a%b);
}

int gcd(int a[], int n){
	int cur = a[0];
	for (int i = 1; i < n; i += 1){
		cur = gcd(cur, a[i]);
	}
	// cout << "Finding gcd is over now returning the final" << endl;
	return cur;
}

int main(void){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int G = gcd(a, n);
	// cout << "Final gcd is " << G << endl;
	vector<int> prime_factors;
	int d = 2;
	if(G%d == 0){
		prime_factors.push_back(d);
		while(G%d == 0){
			G /= d;
		}
	}
	// cout << "Passed d = 2" << endl;
	d = 3;
	while(d <= G && d <= 100000){
		// cout << "d = " << d << endl;
		if(G%d == 0){
			// cout << "appending d=" << d << endl;
			prime_factors.push_back(d);
			while(G%d == 0){
				G /= d;
			}
		}
		d += 2;
	}
	if(G > 1){
		prime_factors.push_back(G);
	}
	int maximum = 0;
	for (int i = 0; i < prime_factors.size(); i += 1){
		maximum = max(maximum, (k/prime_factors[i]) * prime_factors[i]);
	}
	cout << maximum << endl;
}