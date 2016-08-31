/*input
1 1
W
*/

#include <bits/stdc++.h>

using namespace std;

bool bw(char a[], int n){
	for (int i = 0; i < n; i += 1){
		if (a[i] == 'C' or a[i] == 'M' or a[i] == 'Y'){
			return false;
		}
	}
	return true;
}

int main(void){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	char a[n*m];
	int k = 0;
	for (int i = 0; i < n*m; i += 1){
		cin >> a[k++];
	}	
	if (bw(a, n*m)){
		cout << "#Black&White" << endl;
	}else{
		cout << "#Color" << endl;
	}
}