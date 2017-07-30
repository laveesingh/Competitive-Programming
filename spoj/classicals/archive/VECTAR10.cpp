#include <iostream>

using namespace std;

int lp(int n){
	// if (n == 1) return 0;
	n -= 1;
	int msb = 0;
	while(n > 0){
		n >>= 1;
		msb += 1;
	}
	return 1<<(msb-1);
}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	while(true){
		cin >> n;
		if (n == 0) break;
		if (n == 1){
			cout << 1 << endl;
			continue;
		}
		cout << (n-lp(n))*2 << endl;
	}
}