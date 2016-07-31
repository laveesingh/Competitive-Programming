#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isanyremaining(int a[], int n){
	for (int i = 0; i < n; i += 1){
		if (a[i] >= 0) return true;
	}
	return false;
}

int main(void){
	int n, a, b;
	cin >> n >> a >> b;
	int H[n];
	for (int i = 0; i < n; i += 1){
		cin >> H[i];
	}
	vector<int> attacks;
	while(H[0] >= 0){
		attacks.push_back(1);
		H[1] -= a;
		H[0] -= b;
		H[2] -= b;
	}
	while(H[n-1] >= 0){
		attacks.push_back(n-2);
		H[n-2] -= a;
		H[n-1] -= b;
		H[n-3] -= b;
	}
	while(isanyremaining(H, n)){
		int max_index = max_element(H, H+n)-H;
		H[max_index] -= a;
		H[max_index-1] -= b;
		H[max_index+1] -= b;
		attacks.push_back(max_index);
	}
	cout << attacks.size() << endl;
	for (int i = 0; i < attacks.size(); i += 1){
		cout << attacks[i]+1 << " ";
	}
	cout << endl;
}