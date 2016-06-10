#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

#define ull unsigned long long

// ull store = {0, 5, 20, 100, 500, 2500 , 12500 , 62500 , 312500 , 1562500 , 7812500 , 39062500, 195312500};

// ull mod(ull n, ull m){
// 	if(n == m) return n;
// 	return n%m;
// }

string mod_store[] = {"8", "0", "2", "4", "6"};


void solve(ull n){
	string ans = "";
	if (n < 5) {
		cout << mod_store[n] << endl;
		return;
	}
	while (n > 4){
		// cout << "Now the value of n is : " << n << endl;
		ull cur = n%5;
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
		ull n;
		cin >> n;
		solve(n);	
	}

}