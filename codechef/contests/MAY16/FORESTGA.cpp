#include <iostream>
#include <math.h>

using namespace std;

#define ull unsigned long long

int fits(ull n, ull N, ull W, ull L, ull h[], ull r[]){
	ull ans = 0;
	for (int i = 0; i < N; i += 1){
		if (h[i]+r[i]*n >= L){ // may be >= should be >
			ans += h[i]+r[i]*n;
			if (h[i]+r[i]*n >= W || ans > W) return 1;
		}
	}
	if (ans == W) return 0;
	if (ans > W) return 1;
	return -1;
}

ull solve(ull N, ull W, ull L, ull h[], ull r[]){
	ull lo = 0, hi = pow(10,20), mid=0; // try high limit to 20 as well.
	int x;
	while (lo < hi){
		mid = lo + (hi-lo)/2;
		x = fits(mid, N, W, L, h, r);
		if (x == 0){
			return mid;
		}else if(x == 1){
			hi = mid;
		}else{
			lo = mid+1;
		}
	}
	return lo;
}

int main(void){
	ull N, W, L;
	cin >> N >> W >> L;
	ull h[N], r[N];
	for (int i = 0; i < N ; i += 1){
		cin >> h[i] >> r[i];
	}
	cout << solve(N, W, L, h, r) << endl;
}