#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n,t;
	cin >> t;
	while(t--){
		
		cin >> n;
		int a[n];

		for(int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		int z = count(a, a+n, 0);
		if(n == 1){
			if(z == 0){
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}else{
			if(z == 1){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
}