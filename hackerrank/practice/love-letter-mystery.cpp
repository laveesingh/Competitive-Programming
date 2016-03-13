#include <iostream>
#include <cmath>

using namespace std;

int solve(string a){
	int ans = 0;
	int l = a.length();
	for (int i = 0; i < l/2; i += 1){
		ans += abs(a[i] - a[l-i-1]);
	}
	return ans;
}

int main(void){
	int t; 
	string a;
	cin >> t;
	while (t--){
		cin >> a;
		cout << solve(a) << endl;
	}
}