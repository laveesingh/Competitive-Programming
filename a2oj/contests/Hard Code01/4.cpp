#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void print(int a[], int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] <<  " " ;
	}
	cout << endl;
}

int main(void){
	int n, m;
	cin >> n;
	int boys[n];
	for (int i = 0; i < n; i += 1){
		cin >> boys[i];
	}
	cin >> m;
	int girls[m];
	for (int i = 0; i < m; i += 1){
		cin >> girls[i];
	}
	sort(boys, boys+n);
	sort(girls, girls+m);
	// print(boys, n);
	// print(girls, m);
	int ans = 0;
	int i = 0;
	int j = 0;
	while(i < n && j < m){
		// cout << "boys["<<i<<"] is " << boys[i] << " and girls["<<j<<"] is " << girls[j] << endl;
		if(abs(boys[i]-girls[j]) < 2){
			i++;j++;ans++;
		}else{
			if(boys[i]<girls[j]){
				i++;
			}else{
				j++;
			}
		}
	}
	cout << ans << endl;
}