#include <bits/stdc++.h>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int total = accumulate(a, a+n, 0) * 2;
	total /= n;
	int visited[n];
	fill_n(visited, n, 0);
	for (int i = 0; i < n-1; i += 1){
		if (!visited[i]){

			for (int j = i+1; j < n; j += 1){
				if (!visited[j] and a[i]+a[j] == total){
					cout << i+1 << " " << j+1 << endl;
					visited[i] = 1;
					visited[j] = 1;
					break;
				}
			}
		}
	}
}