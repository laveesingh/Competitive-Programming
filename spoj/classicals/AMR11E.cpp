#include <vector>
#include <iostream>

using namespace std;

vector<int> prime_factors(int n){
	vector<int> f;
	if (n%2 == 0){
		f.push_back(2);
		while (n%2 == 0) n/= 2;
	}
	int i = 3;
	while (i*i <= n){
		if (n % i == 0){
			f.push_back(i);
			while (n%i == 0) n /= i;
		}
		i += 2;
	}
	if (n != 1) f.push_back(n);
	return f;
}

vector<int> luckys;

int main(void){

	for (int i = 30; i <= 30000; i += 1){
		vector<int> f = prime_factors(i);
		if (f.size() >= 3){
			luckys.push_back(i);
		}
		if (luckys.size() >= 1000) break;
	}
	int t,n;
	cin >> t;
	while (t--){
		cin >> n;
		n -= 1;
		cout << luckys[n] << endl;
	}

}


