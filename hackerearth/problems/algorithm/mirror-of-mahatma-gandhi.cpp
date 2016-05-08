#include <iostream>

using namespace std;

bool solve(string a){
	int n = a.length();
	for (int i = 0; i < (n+1)/2; i += 1){
		if (a[i] != '1' && a[i] != '8' && a[i] != '0') return false;
		else{
			if (a[i] != a[n-i-1]) return false;
		}
	}
	return true;
}

int main(void){
	int t;
	cin >> t;
	string a;
	while(t--){
		cin >> a;
		cout << (solve(a) ? "YES" : "NO") << endl;
	}
}