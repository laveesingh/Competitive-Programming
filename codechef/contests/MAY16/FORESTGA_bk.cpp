#include <iostream>
#include <math.h>

using namespace std;

#define ll unsigned long long

ll *h, *r, n;

ll fits(ll mid, ll w, ll l){
	ll sum = 0;
	for (ll i = 0; i < n; i += 1){
		// cout << "the value of l is: " << l << " and current sum is: h[i]" << h[i] << " r[i]: " << r[i] << " mid: " << mid << " exp: " << h[i]+r[i]*mid << endl; 
		if(h[i]+r[i]*mid >= l){

			sum += h[i]+r[i]*mid;
			if (sum >= w || h[i]+r[i]*mid>=w) return 1;
		}
	}
	// cout << "Sum: " << sum << "    ";
	if (sum >= w) return 1;
	return -1;
}


int main(void){
	ll w, l;
	cin >> n >> w >> l;
	h = new ll[n];
	r = new ll[n];
	for (ll i = 0; i < n; i += 1){
		cin >> h[i] >> r[i];
	}
	ll lo = 0, mid, hi = pow(10,18), sum, lastmid = 0;
	string flag = "todo";

	while (lo < hi){
		mid = lo + (hi - lo)/2;
		// cout << "the lo: " << lo << " hi: " << hi <<	 " The mid value is: " << mid << endl;
		if (mid == lastmid){
			flag = "done";
			cout << mid << endl;
			break;
		}
		sum = 0;
		ll f = fits(mid, w, l);
		
		if(f == -1){
			lo = mid+1;
		}else{
			hi = mid;
		}
		lastmid = mid;

	}
	if (flag != "done"){
		if (fits(lo, w, l)){
			cout << lo << endl;
		}else{
			cout << hi << endl;
		}
	}
}