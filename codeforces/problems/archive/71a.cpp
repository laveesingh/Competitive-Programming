#include <iostream>
#include <cstdio>
using namespace std;

string solve(string a){
	if (a.length() < 11) return a;
	return a[0]+to_string(a.length()-2)+a[a.length()-1];
}

int main(void){
	int n ;
	cin >> n;
	while (n--){
		string a;
		cin >> a;
		cout << solve(a) << endl;
	}
}