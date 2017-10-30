#include <iostream>

using namespace std;

bool solve(string a){
	string b = "hello";
	int j = 0;
	for (int i = 0; i < a.length(); i += 1){
		if (a[i] == b[j]){
			j += 1;
		}
		if (j >= b.length()) return true;
	}
	return false;
}

int main(void){
	string a;
	cin >> a;
	cout << (solve(a) ? "YES" : "NO") << endl;
}