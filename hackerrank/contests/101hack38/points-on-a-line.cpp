#include <iostream>
#include <utility>

using namespace std;


#define pii pair<int, int>

#define mp make_pair

string solve(int n){
	pii a[n];
	int x, y;
	for (int i = 0; i < n; i += 1){
		cin >> x >> y;
		a[i] = mp(x, y);
	}
	bool flag1 = false;
	bool flag2 = false;
	for (int i = 1; i < n; i += 1){
		if(a[i].first != a[i-1].first){
			flag1 = true;
		}
		if(a[i].second != a[i-1].second){
			flag2 = true;
		}

	}
	if(flag1 == true && flag2 == true){
			return "NO";
		}
	return "YES";
}

int main(void){
	int n;
	cin >> n;
	cout << solve(n) << endl;
}