#include <bits/stdc++.h>

using namespace std;

bool ispal(string a){
	string b(a.rbegin(), a.rend());

//	cerr << "a: " << a << " rev: " << b << endl;
	return a == b;
}

bool solve(string a){
	int n = a.length();
	if (ispal(a)) return true;

	for(int i = 0; i < n/2; i += 1){
		int j = n-i-1;
		if (a[i] != a[j]){
			string b(a.begin(), a.end());
			a.erase(a.begin()+i, a.begin()+i+1);
			b.erase(b.begin()+j, b.begin()+j+1);
//			cerr << a << " " << b << endl;	
		
			return ispal(a) or ispal(b);
		}
	}

	return false;
}


int main(void){
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		cout << (solve(a) ? "YES" : "NO") << endl;
	}
}
