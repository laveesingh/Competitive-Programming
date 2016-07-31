#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// string solve(int n, int m, int D, vector<int> h){
// 	sort(h.begin(), h.end());
// 	while(m--){
// 		if (h.empty())return "NO";
// 		int cur = h.back();
// 		if (cur <= D){
// 			h.pop_back();
// 			m += 1;
// 		}else{
// 			if(h.empty()) return "NO";
// 			else{
// 				h[h.size()-1] -= D;
// 			}
// 		}
// 	}
// 	return "YES";
// }

string solve(int n, int m, int D, vector<int> h){
	int ans = 0;
	for (int i = 0; i < n; i += 1){
		// cout << "i: " << i << " h[i]: " << h[i] << endl;
		ans += (h[i]-1)/D;
		if (ans >= m) return "YES";
	}
	if (ans >= m) return "YES";
	return "NO";
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n, m, D;
		cin >> n >> m >> D;
		vector<int> h(n);
		for (int i = 0; i < n; i += 1){
			cin >> h[i];
		}
		// cout << "Solving problem" << endl;
		cout << solve(n, m, D, h) << endl;
	}
}