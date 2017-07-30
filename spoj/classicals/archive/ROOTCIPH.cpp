/*input
1
-6 11 -6
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		long long a, b, c;
		cin >> a >> b >> c;
		cout << a*a-2*b << endl;
	}
}
