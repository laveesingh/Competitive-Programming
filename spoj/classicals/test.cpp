#include <bits/stdc++.h>

using namespace std;

#define ZERO(a) memset(a,-1,sizeof(a))

int square(int a[], int n){
	for(int i = 0; i < n; i += 1) a[i] *= a[i];
}

int main(void){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i += 1) a[i] = i;
	square(a, n);
	for(int i = 0; i < n; i += 1) cout << a[i] << " ";;
	cout << endl;
}
