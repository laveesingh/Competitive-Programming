#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

map<pii, int> store;

int solve(int a, int b){
	if (store[mp(a,b)]) return store[mp(a,b)];
	if (a <= 0 || b <= 0){
		return 0;
	}else{
		a += 3;
		b += 2;
		int x = 2+max(solve(a-5, b-10), solve(a-20, b+5));
		store[mp(a-3,b-2)] = x;
		return x;

	}
}

int main(void){
	int t, b, c;
	cin >> t;
	while (t--){
		cin >> b >> c;
		store.clear();
		cout << solve(b,c)-1 << endl;
		
	}
}