#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPal(int n){
	int num = n;
	int rev = 0;
	int dig;
	while (n > 0){
		dig = n % 10;
		rev = rev * 10 + dig;
		n /= 10;
	}
	return rev == num;

}

int main(void){
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		cout << isPal(n) << endl;
	}
}