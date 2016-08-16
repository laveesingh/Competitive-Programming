#include <bits/stdc++.h>

using namespace std;

int digits(int a){
	int cnt = 0;
	while(a > 0){
		cnt++;
		a /= 10;
	}
	return cnt;
}

bool isir(int n){
	int x = digits(n);
	if(digits(n+1) > digits(n)) return false;
	int y = digits(n+n+1);
	return y == x+1;
}

int main(void){
	ios::sync_with_stdio(false);
	int x, n;
	cin >> x >> n;
	string xs = to_string(x);
	for (int i = 0; i < n-1; i += 1){
		xs += to_string(x);
	}
	x = stoi(xs);
	// cout << "x: " << x << endl;
	int cnt = 0;
	for (int i = 1; i < x; i += 1){
		if(isir(i)){
			// cout << i << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
}