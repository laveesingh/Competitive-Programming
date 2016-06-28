#include <cstdio>
#include <iostream>
#include <sstream>

using namespace std;

#define sc(x) scanf("%d", &x)


int main(void){
	int t;
	sc(t);
	string result = "";
	for (int cas = 1 ; cas <= t; cas++){
		int n, K;
		sc(n);
		sc(K);
		int a[n], b[n], c[n],d[n];
		for (int i = 0; i < n; i += 1){
			sc(a[i]);
		}
		for (int i = 0; i < n; i += 1){
			sc(b[i]);
		}
		for (int i = 0; i < n; i += 1){
			sc(c[i]);
		}
		for (int i = 0; i < n; i += 1){
			sc(d[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i += 1){
			for (int j = 0; j < n; j += 1){
				for (int k = 0; k < n; k += 1){
					for (int l = 0; l < n; l += 1){
							// cout << a[i] << " " << b[j] << " " << c[k] << " " << d[l] << " " << K << " " <<  (a[i]^b[j]^c[k]^d[l]) << endl;

						if((a[i]^b[j]^c[k]^d[l]) == K){
							ans += 1;
						}
					}
				}
			}
		}
		// printf("Case #%d: %d\n", cas, ans);
		stringstream ss;
		ss << "Case #" << cas << ": " << ans << endl;
		result += ss.str();
	}
	cout << result;
}