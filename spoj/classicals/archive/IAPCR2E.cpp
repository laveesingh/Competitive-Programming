#include <iostream>
#include <algorithm>

using namespace std;

int a[4];

int main(void){
	int t;
	cin >> t;
	for (int j = 0; j < t; j += 1){
		for (int i = 0; i < 4; i += 1){
			cin >> a[i];
		}
		sort(a, a+4);
		a[3] = min(a[3], 3*(a[0]+a[1]+a[2]));
		long long sum = accumulate(a, a+4, (long long)0);
		cout << "Case " << j+1 << ": " << sum/4 << endl;
	}
}