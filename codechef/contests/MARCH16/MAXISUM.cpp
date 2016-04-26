#include <iostream>
#include <cmath>

using namespace std;

long long interaction(long long a[], long long b[], long long n){
	long long ans = 0;
	for (long long i = 0; i < n; i += 1){
		ans += a[i]*b[i];
	}
	return ans;
}

long long solve(long long a[], long long b[], long long n, long long k){
	long long mn = b[0];
	long long mp = b[0];
	long long ii=0, jj=0;
	for (long long i = 0; i < n; i += 1){
		if (b[i] > mp){
			mp = b[i];
			ii = i;
		}
		if (b[i] < mn){
			mn = b[i];
			jj = i;
		}
	}
	if (abs(b[ii]) > abs(b[jj])){
		if (b[ii] > 0){
			a[ii] += k;
		}else{
			a[ii] -= k;
		}
	}else{
		if (b[jj] > 0){
			a[jj] += k;
		}else{
			a[jj] -= k;
		}
	}
	return interaction(a, b, n);
}

int main(void){

	long long t, n, k;

	cin >> t;
	while(t--){
		cin >> n >> k;
		long long a[n], b[n];
		for (long long i = 0; i < n; i += 1) cin >> a[i];
		for (long long i = 0; i < n; i += 1) cin >> b[i];
		cout << solve(a, b, n, k) << endl;
	}

}