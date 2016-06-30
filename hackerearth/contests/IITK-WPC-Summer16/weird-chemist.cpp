#include <iostream>

using namespace std;

int main(void){
	int n, m, x, y, z;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int sum[n];
	sum[0] = a[0];
	for (int i = 1; i < n; i += 1){
		sum[i] = sum[i-1] + a[i];
	}
	int count = 0;
	for (int i = 0; i < m; i += 1){
		cin >> x >> y >> z;
		x -= 1;
		y -= 1;
		int ans = sum[y];
		if (x > 0) ans -= sum[x-1];
		if (ans >= z) count++;
	}
	cout << count << endl;
}