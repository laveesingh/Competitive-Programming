#include <iostream>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n, k, x, count = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i += 1){
		cin >> x;
		if(x % k == 0) count++;
	}
	cout << count << endl;
}