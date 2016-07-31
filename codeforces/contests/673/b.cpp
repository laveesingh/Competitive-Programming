#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 10000000

int solve(){
	int n, m, x, y;
	cin >> n >> m;
	map<int, int> d1;
	map<int, int> d2;
	int min = INF, max = 0;
	for (int i = 0; i < m; i += 1){
		cin >> x >> y;
		if(x > y && (d2[x]==1 || d1[y]==1 || y > min || x < max)){
			return 0;
		}else if(x < y && (d2[y] == 1 || d1[x]==1 || x > min || y < max)){
			return 0;
		}
		if (x > y){
			d1[x] = 1;
			d2[y] = 1;
			if (x < min) min = x;
			if (y > max) max = y;
		}else{
			d1[y] = 1;
			d2[x] = 1;
			if (y < min) min = y;
			if (x > max) max = x;
		}

	}
	vector<int> a;
	int p = 0;
	for (int i = 1; i <= n; i += 1){
		if(!d1[i] && !d2[i]){
			a.push_back(i);
		}
	}
	for (int i = 0; i < a.size(); i += 1){
		if (a[i] > min){
			d1[a[i]] = 1;
		}else if(a[i] < max){
			d2[a[i]] = 1;
		}else{
			p += 1;
			d2[a[i]] = 1;
		}
	}
	return m==0 ? p-1 : p+1;
	// return p+1;
}

int main(void){
	cout << solve() << endl;
}