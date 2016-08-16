/*input
2
11111110
10101010101010
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		int n = a.length();
		string ans = "Bad";
		for (int i = 1; i < n-1; i += 1){
			if (a[i] == '0' and a[i-1] == '1' and a[i+1] == '1'){
				ans = "Good";
				break;
			}else if(a[i] == '1' and a[i-1] == '0' and a[i+1] == '0'){
				ans = "Good";
				break;
			}
		}
		cout << ans << endl;
	}	
}