#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

class rect{
public:
	int width, height;
};

pii *desired;
map<pii, int> store;

// int solve(int w, int h, int n){
// 	if (store[mp(w,h)]) return store[mp(w,h)];
// 	if (w <= 0 || h <= 0){
// 		return store[mp(w,h)] = 0;
// 	}
// 	vector<int> temp;
// 	int flag = 0;
// 	for (int i = 0; i < n; i += 1){
// 		pii s = desired[i];
// 		if (s.first <= w && s.second <= h){
// 			flag = 1;
// 			temp.push_back(min(s.second*(w%s.first)+solve(w,h-s.second, n), s.first*(h%s.second)+solve(w-s.first,h, n)));
// 		}
// 	}
// 	if (flag == 0) return h*w;
// 	return store[mp(w,h)] = *min_element(temp.begin(), temp.end());
// }


int solve(int w, int h, int n){
	int dp[w+1][h+1];
	for (int i = 0; i <= w; i += 1){
		for (int j = 0; j <= h; j += 1){
			dp[i][j]= i*j;
		}
	}
	for (int i = 0; i < n; i += 1){
		pii s = desired[i];
		dp[s.first][s.second] = 0;
	}
	for (int i = 0; i <= w; i += 1){
		for (int j = 0; j <= h; j += 1){
			// if (i == 0 || j == 0){
			// 	dp[i][j] = 0;
			// }else{
			// 	vector<int> temp;
			// 	int flag = 0;
			// 	for (int k = 0; k < n; k += 1){
			// 		pii s = desired[k];
			// 		if (s.first <= i && s.second <= j){
			// 			flag = 1;
			// 			temp.push_back(min(s.second*(i%s.first)+dp[i][j-s.second], s.first*(j%s.second)+dp[i-s.first][j]));
			// 		}
			// 	}
			// 	if (flag == 0) dp[i][j] = i*j;
			// 	else dp[i][j] = *min_element(temp.begin(), temp.end());
			// }
			for (int k = 0; k <= i; k += 1){
				dp[i][j]  = min(dp[i][j], dp[k][j]+dp[i-k][j]);
			}
			for (int k = 0; k <= j; k += 1){
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]);
			}
		}
	}
	return dp[w][h];
}


int main(void){
	int t, w, h, n, x, y;
	cin >> t;
	while (t--){
		cin >> w >> h;
		cin >> n;
		desired = new pii[n];
		for (int i = 0; i < n; i += 1){
			cin >> x >> y;
			desired[i] = mp(x, y);
		}
		cout << solve(w, h, n) << endl;
		delete[] desired;
	}
}