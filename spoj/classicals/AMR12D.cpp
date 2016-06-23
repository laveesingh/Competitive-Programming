#include <iostream>
#include <algorithm>

using namespace std;

string reversed(string a){
	reverse(a.begin(), a.end());
	return a;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		if(a == reversed(a)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}

