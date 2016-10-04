#include <bits/stdc++.h>

using namespace std;

int main(void){

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
		while(a[i] %2 == 0) a[i] /= 2;
		while(a[i]%3 == 0) a[i] /= 3;
	}
	int base = a[0];
	for(int i = 0; i < n; i += 1){
		if (base != a[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}

