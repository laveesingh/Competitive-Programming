/*input
zzzz
*/


#include <bits/stdc++.h>

using namespace std;

string shift(string b){
	for (int i = 0; i < b.length(); i += 1){
		b[i] = b[i]-1;
	}
	return b;
}

int main(void){
	ios::sync_with_stdio(false);
	string a;
	cin >> a;
	int n = a.length();
	int flat = 0;
	int i = 0, j=0;
	while(i < n and a[i] == 'a'){
		i++;
	}
	if (i == n){
		a[n-1] = 'z';
		cout << a << endl;
	}else{
		j = i;
		int sz = 0;
		while(j < n and a[j] != 'a'){
			sz++;
			j++;
		}
		// cout << "i: " << i << " j: " << j << " sz: " << sz << endl;
		string ans = a.substr(0,i) + shift(a.substr(i,sz)) + a.substr(j);
		cout << ans << endl;
	}
}