#include <iostream>

using namespace std;

int main(void){
	int t, n, x, y, z, max = 100000;
	cin >> t;
	while (t--){
		cin >> n;
		// vector<int> a;
		for (int i = 0; i < n-1; i += 1){
			cin >> x >> y >> z;
			if (z < max) max = z;
		}
		cout << z << endl;
		for (int i = 0; i < n-1; i += 1){
			cout << "0" << endl;
		}
	}
}