#include <iostream>
#include <algorithm>

using namespace std;


#define ull unsigned long long

ull solve(){
	int m, n;
	cin >> m >> n;
	int H[m-1];
	int V[n-1];
	ull cost = 0;
	int h = 1, v = 1;
	for (int i = 0; i < m-1;  i += 1){
		cin  >> H[i];
	}
	for (int i = 0; i < n-1; i += 1){
		cin >> V[i];
	}
	sort(V, V+n-1);
	sort(H,H+m-1);
	int i = n-2, j = m-2;
	while(i >= 0 || j >= 0){
		if (i >= 0 && j >= 0){
			if (V[i] >= H[j]){
				cost += V[i]*h;
				v += 1;
				i -= 1;
			}else{
				cost += H[j]*v;
				h += 1;
				j -= 1;
			}
		}else if(i >= 0){
			cost += V[i]*h;
			v += 1;
			i -= 1;
		}else{
			cost += H[j]*v;
			h += 1;
			j -= 1;
		}
	}
	return cost;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		cout << solve() << endl;
	}
}