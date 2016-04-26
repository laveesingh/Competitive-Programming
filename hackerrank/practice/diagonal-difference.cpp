#include <iostream>
#include <cmath>

using namespace std;


int main(void){
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j += 1){
			cin >> a[i][j];
		}
	}
	int
		d1 = 0, d2 = 0;
	for (int i = 0; i < n; i += 1){
		d1 += a[i][i];
		d2 += a[i][n-i-1];
	}
	cout << abs(d1 - d2) << endl;
}