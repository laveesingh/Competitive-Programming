#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int ans = 0;
		set<char> ss(s.begin(), s.end());
		for(char x: ss){
			int freq = count(s.begin(), s.end(), x);
			ans += (freq+1)/2;
		}
		cout << ans << endl;
	}
}