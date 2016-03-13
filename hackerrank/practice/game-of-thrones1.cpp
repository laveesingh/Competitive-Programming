#include <iostream>
#include <map>

using namespace std;

bool solve(string a){
	map <char, int> mp;
	int ans = 0;
	int cur;
	for (char x: a){
		mp[x] += 1;

	}
	for (map<char, int>::const_iterator it = mp.begin(); it != mp.end(); ++it){
		cur = it -> second;
		if (cur%2){
			ans += 1;
		}if(ans > 1){
			return false;
		}
	}
	return true;
}


int main(void){
	string a;
	cin >> a;
	cout <<  (solve(a) ? "YES" : "NO") << endl;
}