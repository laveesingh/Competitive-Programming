#include <bits/stdc++.h>

using namespace std;

#define ll long long

// ll store = {0, 5, 20, 100, 500, 2500 , 12500 , 62500 , 312500 , 1562500 , 7812500 , 39062500, 195312500};

// ll mod(ll n, ll m){
// 	if(n == m) return n;
// 	return n%m;
// }

string mod_store[] = {"8", "0", "2", "4", "6"};


void nth(ll n){
	string ans = "";
	if (n < 5) {
		cout << mod_store[n] << endl;
		return;
	}
	while (n > 4){
		// cout << "Now the value of n is : " << n << endl;
		ll cur = n%5;
		// ans.push_front(mod_store[cur]);
		ans = mod_store[cur]+ans;
		if(n%5 == 0){
			n /= 5;
		}else{

			n /= 5;
			n += 1;
		}
	}
	if (n > 1){
		ans = mod_store[n] + ans;
	}
	cout << ans << endl;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		nth(n);	
	}

}