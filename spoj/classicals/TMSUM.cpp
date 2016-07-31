#include <iostream>
#include <algorithm>

using namespace std;

bool rev(int a, int b){
	if (a <= b) return false;
	return true;
}

int main(void){
	int t, n, np, nn, temp;
	cin >> t;
	while (t--){
		np = 0, nn = 0;
		cin >> n;
		int a[n];
		int b[n];
		for (int i = 0; i < n; i += 1){
			cin >> temp;
			if (temp > 0){
				a[np] = temp;
				np += 1;
			}else{
				b[nn] = temp;
				nn += 1;
			}

		}
		
		// for (int i = 0; i <= nn; i += 1){
		// 	cout << b[i] << " ";
		// }
		// cout << endl;
		int ans = 0;
		if (np != 0){
			// cout << "We passed the first condition." << endl;
			np -= 1;
			sort(a,a+np+1);

			for (int i = np; i > 1; i -= 2){
				// cout << "i: " << i << endl;
				ans += a[i]*a[i-1];
			}
			if ((np+1)%2){
				ans += a[0];
			}else{
				ans += a[0]*a[1]>a[0]+a[1]?a[0]*a[1]:a[0]+a[1];
			}
		}
		// cout << "THe answer yet  is: " << ans << endl;
		if (nn != 0){
			// cout << "We passed the second condition." << endl;
			nn -= 1;
			// cout << "The value of nn is " << nn << endl;
			sort(b, b+nn+1, rev);
			for (int i = nn; i >= 1; i -= 2){
				// cout << "i: " << i << endl;
				// cout << "toadd : " << b[i]*b[i-1] << endl;
				ans += b[i]*b[i-1];
			}
			// cout << "The answer before the last addition is " << ans << endl;
			if ((nn+1)%2) ans += b[0];
		}
		cout << ans << endl;
		
	}
}