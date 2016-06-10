#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(c) c.begin(), c.end()

vector<int> prod(vector<int> a, vector<int> b){
	for (int i =0 ; i < b.size(); i += 1){
		b[i] += a.size();
	}
	copy(all(b), back_inserter(a));
	return a;
}

int max2i(int n){
	for (int i = 0; i < 100; i += 1){
		if (pow(2,i) <= n && pow(2,i+1) > n){
			return pow(2,i);
		}
	}
}


void Print(vector<int> a){
	for (int i = 0; i < a.size(); i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(void){
	int n;
	cin >> n;
	while(n > 0){
		cout << max2i(n) << endl;
		n -= max2i(n);
	}
}