#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a[n];
		for(int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		int cnt = 0;
		int i = n-1, j = n-1;
		int cold[n], rowd[n];
		fill_n(cold, n, 0);
		fill_n(rowd, n, 0);
		while (i >= 0){
			for (int ii = i; ii >= 0; ii -= 1){
				if (a[ii][j] == '.' && !cold[j] && !rowd[ii]){
					cnt++;
				}else if(a[ii][j] == '#'){
					cold[j] = 1;
					rowd[ii] = 1;
				}
			}
			for(int jj = j-1; jj >= 0; jj -= 1){
				if(a[i][jj] == '.' && !cold[jj] && !rowd[i]){
					cnt++;
				}else if(a[i][jj] == '#'){
					cold[jj] = 1;
					rowd[i] = 1;
				}
			}
			i--;
			j--;
		}
		cout << cnt << endl;
	}
}