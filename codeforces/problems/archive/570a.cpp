#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;
	int won[n];
	int cur[n];
	fill_n(won, n, 0);
	for (int i = 0; i < m; i += 1){
		for (int j = 0; j < n; j += 1){
			cin >> cur[j];
		}
		int max = *max_element(cur, cur+n);
		for (int j = 0; j < n; j += 1){
			if (cur[j] == max){
				won[j] += 1;
				break;
			}
		}
	}
	int max = *max_element(won, won+n);
	int ans;
	for (int i = 0; i < n; i += 1){
		if (won[i] == max){
			ans = i+1;
			break;
		}
	}
	cout << ans << endl;
}