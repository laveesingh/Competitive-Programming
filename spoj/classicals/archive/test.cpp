#include <bits/stdc++.h>

using namespace std;

int store[10][10];

int main(void){
	int n;
	cin >> n;
	memset(store, -1, sizeof(store));
	for(int i = 0; i < 10; i += 1){
		for(int j = 0; j < 10; j += 1) cout << store[i][j] << " ";
		cout << endl;
	}
}
