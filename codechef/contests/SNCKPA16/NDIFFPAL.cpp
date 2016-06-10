#include <iostream>

using namespace std;

string let = "abc";

int main(void){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		string ans = "";
		for (int i = 0; i < n; i += 1){
			ans.push_back(let[i%3]);
		}
		cout << ans << endl;
	}
}