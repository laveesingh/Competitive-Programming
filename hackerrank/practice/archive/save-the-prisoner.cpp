#include <bits/stdc++.h>

using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n, m, s;
		cin >> n >> m >> s;
		m %= n;
		int res =  (m+s-1)%n;
		cout << (res==0 ? n : res) << endl;
	}
}