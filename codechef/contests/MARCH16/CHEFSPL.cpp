#include <iostream>

using namespace std;

bool solve(string a){
	if (a.length()%2 == 0){
		//cout << a.substr(0, a.length()/2) << " " << a.substr(a.length()/2) << endl;
		return a.substr(0, a.length()/2) == a.substr(a.length()/2);
	}else{
		for (int i = 0; i < a.length(); i += 1){
			//cout <<" Stuck in for loop" << endl;
			string c = i < a.length()-1 ? (a.substr(0,i)+a.substr(i+1)) : a.substr(0,i);
			bool b = solve(c);
			if (b) return true;
		}
	}
	return false;
}

int main(void){
	int t;
	cin>> t;
	while(t--){
		string a;
		cin >> a;
		cout << (solve(a)?"YES":"NO") << endl;
	}
}