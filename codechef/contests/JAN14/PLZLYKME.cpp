#include <iostream>

using namespace std;

bool solve(int l, int d, int s, int c){
	unsigned long long ans = s;
	while (d-- > 1){
		ans += ans * c;
		if (ans >= l) return true;
	}
	return ans >= l ? true : false;
}
int main(void){
	int t;
	int l, d, s,c;
	cin >> t;
	while (t--){
		cin >> l >> d >> s >> c;
		cout << (solve(l, d, s, c) ? "ALIVE AND KICKING" : "DEAD AND ROTTING") << endl;
	}
}