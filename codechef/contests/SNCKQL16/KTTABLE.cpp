#include <iostream>

using namespace std;

int main(void){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n],b[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i] ;
		}
		for (int i = 0; i < n; i += 1){
			cin >> b[i] ;
		}
		int cur = 0, total = 0;
		for (int i = 0; i < n; i += 1){
			if (a[i]-cur >= b[i]){
				total += 1;
			}
			cur = a[i];
		}
		cout << total << endl;
	}
}