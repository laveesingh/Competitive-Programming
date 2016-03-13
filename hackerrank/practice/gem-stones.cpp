#include <iostream>
#include <map>
#include <vector>

using namespace std;



int solve(string a[], int n){
	vector<map<char, int>> v;
	for (int i = 0; i < n; i += 1){
		map<char, int> mp;
		for (int j = 0; j < a[i].length(); j += 1){
			mp[a[i][j]] = 1;
		}
		v.push_back(mp);
	}
	map<char, int> temp;

	for (int i = 0; i < n; i += 1){
		for (map<char, int>::const_iterator it = v[i].begin(); it != v[i].end(); ++it){
			temp[it->first] += 1;
		}
	}
	int ans = 0;
	for (map<char, int>::const_iterator it = temp.begin(); it != temp.end(); ++it){
		if (it->second < n){
			ans += 0;
		}else{
			ans += 1;
		}
	}
	return ans;
}

int main(void){
	int n;
	cin >> n;
	string a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	cout << solve(a, n) << endl;

}