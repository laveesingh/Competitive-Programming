#include <bits/stdc++.h>

using namespace std;

inline bool similar(const string& a, const string& b){
	for(int i = 0; i < a.length(); i += 1){
		for(int j = i; j < a.length(); j += 1){
			if(a[i] == a[j] and b[i] == b[j]){
				// do nothing
			}else if(a[i] != a[j] and b[i] != b[j]){
				// do nothing
			}else{
				return false;
			}
		}
	}
	return true;
}

map<string, int> store;

int main(void){
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	int x, y;
	for(int i = 0; i < m; i += 1){
		cin >> x >> y;
		x -= 1;
		string cur = a.substr(x, y-x);
		if (store.find(cur) != store.end()){
			cout << store[cur] << endl;
		}else{
			int ans = 0;
			for(int i = 0; i < n-cur.length()+1; i += 1){
				if(similar(cur, a.substr(i, cur.length()))) ans++;
			}
			store[cur] = ans;
			cout << ans << endl;
		}

	}
		

}