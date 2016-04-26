#include <iostream>
#include <vector>

using namespace std;

unsigned long long max(vector<unsigned long long> a){
	unsigned long long max = 0;
	for (unsigned long long i = 0; i<a.size(); i += 1){
		if (a[i] > max) max = a[i];
	}
	return max;
}

unsigned long long primeF(long long n){
	vector<unsigned long long> a;
	if (!(n%2)){
		a.push_back(2);
		while (!(n%2)){
			n /= 2;
		}
	}
	unsigned long long b = 3;
	if (n == 1) return 2;
	while (b*b <= n){
		if (!(n%b)){
			a.push_back(b);
			while (!(n%b)){
				n /= b;
			}
		}
		b += 2;
	}
	a.push_back(n);
	return max(a);
}

int main(void){
	unsigned long long t;
	long long n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << primeF(n) << endl;
	}
}