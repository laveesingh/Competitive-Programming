#include <bits/stdc++.h>

using namespace std;

int syl(string a){
	int count = 0;
	for(char s: a){
		if (s == 'a' or s == 'e' or s == 'i' or s == 'o' or s == 'u' or s == 'y'){
			count += 1;
		}else{
			// do nothing
		}
	}
	return count;
}

int main(void){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int b[n];
	string ans = "YES";
	for(int i = 0; i < n; i += 1){
		string temp;
		// cin >> temp;
		getline(cin, temp);
		cout << "Temp:" << temp << endl;
		b[i] = syl(temp);
		if (b[i] != a[i]){
			cout << b[i] << " " << a[i] << endl;
			ans = "NO";
			// break;
		}
	}
	cout << ans << endl;
}