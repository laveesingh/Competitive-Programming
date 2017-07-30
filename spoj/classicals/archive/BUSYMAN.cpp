#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// int comp(pair<int, int> a, pair<int, int> b){
// 	if (a.second <= b.second) return 1;
// 	return 0;
// }

// int solve(vector<pair<int, int>> a){
// 	sort(a.begin(), a.end(), comp);
// 	// for (pair<int, int> x : a){
// 	// 	cout << x.first << " " << x.second << endl;
// 	// }
// 	int activities = 1;
// 	pair<int, int> cur = a[0];
// 	int end = cur.second;
// 	for (int i = 1; i < a.size(); i += 1){
// 		cur = a[i];
// 		if (cur.first >= end){
// 			activities += 1;
// 			end = cur.second;
// 		}
// 	}
// 	return activities;
// }

// int main(void){
// 	int t,s,n,f;
// 	cin >> t;
// 	while (t--){
// 		cin >> n;
// 		vector <pair<int, int>> a;
// 		for (int i = 0; i < n; i+= 1){
// 			cin >> f >> s;

// 			a.push_back(make_pair(f,s));
// 		}
// 		cout << solve(a) << endl;
// 	}
// }

class act{
	
public:
	int start, end;
	act(){}
	act(int a, int b){
		start = a;
		end = b;
	}

};

bool compare(act a, act b){
	if (a.end < b.end) return true;
	if (a.end == b.end) return a.start<b.start;
	return false;
}

int main(void){
	int t,n,x,y,cnt,etime;
	cin >> t;
	while (t--){
		cin >> n;
		vector<act> a(n);
		for (int i = 0; i < n; i += 1){
			cin >> x >> y;
			act temp = act(x, y);
			a[i] = temp;
		}
		sort(a.begin(),a.end(),compare);
		cnt = 1;
		etime = a[0].end;
		for (int i = 1; i < n; i += 1){
			act temp = a[i];
			if (temp.start >= etime){
				cnt += 1;
				etime = temp.end;
			}
		}
		cout << cnt << endl;

	}
}
