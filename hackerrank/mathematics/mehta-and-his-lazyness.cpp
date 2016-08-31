/*input
4
2
8
36
900
*/

#include <bits/stdc++.h>

using namespace std;

#define gcd(a,b) __gcd(a,b)

bool evenPS(int n){
	if(n%2) return false;
	if(sqrt(n) == (int)sqrt(n)) return true;
	return false;
}

void solve(int n){
	// cout << "Finding divisors for n: " << n <<endl;
	vector<int> divs;
	divs.push_back(1);
	for (int i = 2; i <= sqrt(n); i += 1){
		if(n%i == 0){
			// cout << i << " divides " << n<< endl;
			if(i == sqrt(n)){
				divs.push_back(i);
			}else{
				divs.push_back(i);
				divs.push_back(n/i);
			}
		}
	}
	int x  = 0;
	for (int i = 0;i < divs.size(); i += 1){
		if(evenPS(divs[i])){
			x += 1;
		}
	}
	if (x == 0){
		cout << 0 << endl;
		return;
	}
	int y = divs.size();
	int g = gcd(x,y);
	cout << x/g << "/" << y/g << endl;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		solve(n);
	}
}
