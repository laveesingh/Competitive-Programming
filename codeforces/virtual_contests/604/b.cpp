/*input
3 2
3 5 7
*/

#include <bits/stdc++.h>

using namespace std;


int n, k;
int *a;

bool fits(int s){
	int visited[n];
	fill_n(visited, n, 0);
	int cnt = 0;
	int i = 0, j = n-1;
	while (i < j){
		if (a[i]+a[j] <= s){
			visited[i] = 1;
			visited[j] = 1;
			i++;
			j--;
			cnt += 1;
		}else{
			j--;
		}
	}
	for (i = 0; i < n; i += 1){
		if (!visited[i]) cnt++;
	}
	return cnt <= k;
}


int main(void){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	a = new int[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}

	int lo = *max_element(a, a+n), hi = 100000000, s=0;
	while(lo <= hi){
		// cout << lo << " " << hi << endl;
		if (s == (lo + (hi-lo)/2)){
			break;
		}
		s = lo + (hi-lo)/2;
		if (fits(s)){
			hi = s;
		}else{
			lo = s+1;
		}
	}
	cout << lo << endl;

}