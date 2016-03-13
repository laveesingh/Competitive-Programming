/*

* Author: Lavee Singh

*/

#include <iostream>

using namespace std;

int solve(string a){
	int ans = 0;
	char temp = a[0];
	for (int i = 1;i < a.length(); i += 1){
		if (a[i] == temp){
			ans += 1;
		}else{
			temp = a[i];
		}
	}
	return ans;
}

int main(void){
	int t;
	cin >> t;
	string a;
	while(t--){
		cin >> a;
		cout << solve(a) << endl;
	}
}