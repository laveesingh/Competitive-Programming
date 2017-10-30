#include <iostream>

using namespace std;


bool solve(string a){
	int cnt = 1;
	char cur = a[0];
	for (int i = 1; i < a.length(); i += 1){
		if (string(1,cur) == string(1,a[i])){
			cnt += 1;
			if (cnt >= 7) return true;
		}else{
			cur = a[i];
			cnt = 1;
		}
	}
	return false;
}

int main(void){
	string a;
	cin >> a;
	cout << (solve(a) ? "YES" : "NO") << endl;
}