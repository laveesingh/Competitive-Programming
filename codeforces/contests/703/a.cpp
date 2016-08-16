#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[2];
	a[0] = a[1] = 0;
	int x, y;
	for (int i = 0; i < n; i += 1){
		cin >> x >> y;
		a[x<y] += 1;
	}

	if (a[0] > a[1]){
		cout << "Mishka" << endl;
	}else if(a[0] < a[1]){
		cout << "Christ" << endl;
	}else{
		cout << "Friendship is magic!^^" << endl;
	}
}