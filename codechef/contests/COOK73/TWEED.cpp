#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string start;
		cin >> start;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		if (n == 1 && start == "Dee" && a[0]%2 == 0){
			cout << "Dee" << endl;
		}else{
			cout << "Dum" << endl;
		}
	}	
}