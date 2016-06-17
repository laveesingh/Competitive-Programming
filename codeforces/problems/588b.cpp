#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define all(c) c.begin(),c.end()
#define limit 1000001

int main(void){
	ll n;
	cin >> n;
	// scanf("%lld",&n);
	// vector<ll> divisors;
	ll ans = 1;
	int d = 2;
	if(n%d==0){
		while(n%d==0){
			n /= d;
		}
		// divisors.push_back(d);
		ans *= d;
	}
	d += 1;
	while(d <= sqrt(n)+1){
		if(n%d == 0){
			while(n%d==0){
				n/=d;
			}
			// divisors.push_back(d);
			ans *= d;
		}else{
			d += 2;
		}
	}
	if(n > 1){
		ans *= n;
	}
	// ll ans = accumulate(all(divisors), (ll)1, multiplies<ll>());
	cout << ans << endl;
	// printf("%lld\n", ans);
}