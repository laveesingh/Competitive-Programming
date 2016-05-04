#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

vector<ll> a;

ll sum(int i, int j){
	ll ans = 0;
	for(int ii = i; ii < j; ii += 1){
		ans += a[ii];
	}
	return ans;
}

int main(void){
	ll n, k, temp;
	cin >> n >> k;
	for (int i = 0; i < n; i += 1){
		cin >> temp;
		a.push_back(temp);
	}
	vector<ll> final;
	for (int i = 1; i < n+1; i += 1){
		for (int j = 0;j < n-i+1; j += 1){
			final.push_back(sum(j, j+i));
		}
	}
	sort(final.begin(), final.end());
	int m = final.size();
	for (int i = m-1; i >= m-k; i -= 1){
		cout << final[i] << " " ;
	}
	cout << endl;
}