#include <iostream>

using namespace std;

bool isvowel(char a){
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a== 'y'){
		return true;
	}
	return false;
}

bool iscons(char a){
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a== 'y'){
		return false;
	}
	return true;
}

string solve(string a){
	int v = 0, c = 0;
	for (int i = 0; i < a.length(); i += 1){
		if (isvowel(a[i])){
			v += 1;
		}else{
			c += 1;
		}
		if (i >= 2 && (iscons(a[i]) && iscons(a[i-1]) && iscons(a[i-2]))){
			return "hard";
		}
	}
	return c > v ? "hard" : "easy";
}

int main(void){
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		cout << solve(s) << endl;
	}
}