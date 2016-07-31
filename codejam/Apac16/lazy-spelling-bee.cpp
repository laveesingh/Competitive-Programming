#include <iostream>
#include <vector>

using namespace std;

#define ll long long 
const ll mod = 1000000007;

ll solve(string a){
	ll ans = 1;
	ll n = a.length();
	for (ll i = 0; i < n; i += 1){
		if (i == 0 && i == n-1){
			return 1ll;
		}else if(i == 0){
			if(a[i] == a[i+1]){
				ans *= 1;
			} else {
				ans *= 2;
			}
		}else if (i == n-1){
			if(a[i] == a[i-1]){
				ans *= 1;
			} else {
				ans *= 2;
			}
		} else {
			if(a[i-1] == a[i] && a[i] == a[i+1]){
				ans *= 1;
			} else if(a[i-1] == a[i] || a[i] == a[i+1]){
				ans *= 2;
			} else {
				ans *= 3;
			}
		}
		ans %= mod;
	}
	return ans;

}

int main(void){
	vector<string> inputs;
	string temp;
	ll t;
	cin >> t;
	for (int  i = 0; i < t; i += 1){
		cin >> temp;
		inputs.push_back(temp);
	}
	for (int i = 0; i < t; i += 1){
		cout << "Case #" << i+1 << ": " << solve(inputs[i]) << endl; 
	}
}