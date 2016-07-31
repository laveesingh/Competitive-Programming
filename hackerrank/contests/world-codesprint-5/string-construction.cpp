#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		set<char> as(a.begin(), a.end());
		int ans = as.size();
		cout << ans << endl;
	}
}