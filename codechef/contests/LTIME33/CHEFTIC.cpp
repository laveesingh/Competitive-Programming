#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool satisfies(string a[], int i, int j, int k, int n){
	if (a[i][j] != '.') return false;
	int ii;
	int jj;
	int count;

	ii = i;
	jj = j;
	count = 1;
	while (ii++ < n-1 && jj++ < n-1){
		if (a[ii][jj] == 'X') count += 1;
		else break;
	}
	ii=i;
	jj=j;
	while ( ii-- > 0 && jj-- > 0){
		if (a[ii][jj]== 'X')count += 1;
		else break;
	}
	if (count >= k) {
		cout << "i"<<i<<"j"<<j<<"\\ diagonally"<<endl;
		return true;
	}


	ii=i;jj=j;count=1;
	while(ii-- > 0 && jj++ < n-1){
		if (a[ii][jj]== 'X') count += 1;
		else break;
	}
	ii=i;jj=j;
	while (ii++ < n-1 && jj-- > 0){
		if (a[ii][jj] == 'X') count += 1;
		else break;
	}
	if (count >= k) {
		cout << "i"<<i<<"j"<<j<<"/ diagonally"<<endl;
		return true;
	}


	ii=i;jj=j;count=1;
	while(ii-- > 0){
		if (a[ii][jj] == 'X') count += 1;
		else break;
	}
	ii=i;
	while (ii++ < n-1){
		if (a[ii][jj] == 'X') count += 1;
		else break;
	}
	if (count >= k) {
		cout << "i"<<i<<"j"<<j<<" | vertically "<<endl;
		return true;
	}

	ii=i;jj=j;count=1;
	while(jj-- > 0){
		if (a[ii][jj] == 'X') count += 1;
		else break;
	}
	jj=j;
	while(jj++ < n-1){
		if(a[ii][jj] == 'X') count += 1;
		else break;
	}
	if (count >= k) {
		cout << "i"<<i<<"j"<<j<<" -- horizontally."<<endl;
		return true;
	}
}

bool isPossible(string a[], int n, int k){
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j += 1){
			if (satisfies(a, i, j, k, n)){
				return true;
			}
		}
	}
	return false;
}


int main(void){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		string a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		bool sol = isPossible(a, n, k);
		if (sol) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}