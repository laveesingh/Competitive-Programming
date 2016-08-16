/*input
4
1 1
2 2
3 1
3 3
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		if (a > b){
			if (b%2) cout << "D" << endl;
			else cout << "U" << endl;
		}else{
			if (a%2) cout << "R" << endl;
			else cout << "L" << endl;
		}
	}	
}
