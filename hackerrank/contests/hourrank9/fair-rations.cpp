#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int count = 0;
	for (int i = 0; i < n-1;i += 1){
		if (a[i]%2){
			a[i] += 1;
			a[i+1] += 1;
			count += 2;
		}
	}
	if (a[n-1]%2) cout << "NO" << endl;
	else cout << count << endl;
}