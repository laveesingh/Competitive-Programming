/*input
4
abcd
xyz
abcd
bcda
aabc
acaa
Codechef
elfedcc
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		map<char, int> fa, fb;
		for (char s: a) fa[s] += 1;
		for (char s: b) fb[s] += 1;
		int ans = 0;
		for (map<char, int>::iterator it = fa.begin(); it != fa.end(); it++){
			char x = it->first;
			ans += min(fa[x], fb[x]);
		}
		cout << ans << endl;
	}	
}