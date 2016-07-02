#include <iostream>

using namespace std;

int mod = 786433;

int pow(int a, int p){
	if (p == 0) return 1;
	if (p == 1) return a%mod;
	if (p%2) return (a*pow(a,p-1))%mod;
	int x = pow(a, p/2);
	return (x*x)%mod;

}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n+1];
	for (int i = 0; i < n+1; i += 1){
		cin >> a[i];
	}
	int q, x;
	cin >> q;
	for (int i = 0; i < q; i += 1){
		cin >> x;
		int ans = 0;
		for (int j = 0; j <= n; j += 1){
			ans = (ans + a[j]*pow(x, j)) % mod;
		}
		cout << ans << endl;
	}
}