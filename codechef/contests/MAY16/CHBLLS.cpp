#include <iostream>

using namespace std;

int main(void){
	int n, ans;
	cout << 1 << endl;
	cout << 3 << " " << 1 << " " << 1 << " " << 2 << endl;;
	cout << 3 << " " << 3 << " " << 4 << " " << 4 << endl;
	cin >> n;
	if (n == 0) ans = 5;
	if (n == 2) ans = 1;
	if (n == 1) ans = 2;
	if (n == -1) ans = 3;
	if (n == -2) ans = 4;
	cout << 2 << endl;
	cout << ans << endl;
}