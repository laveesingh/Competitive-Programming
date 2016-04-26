#include <iostream>
#include <map>

using namespace std;

bool solve(string a, string b){
	map<char, int> am;
	map<char, int> bm;
	for (char x: a){
		am[x] += 1;
	}
	for (char x: b){
		bm[x] += 1;
	}
	//cout << "am goes as follows " << endl;
	// for(map<char, int>::const_iterator iter=am.begin(); iter != am.end(); ++iter){
	// 	cout << iter -> first << ":" << iter ->second << endl;
	// }
	// for (map<char, int>::const_iterator iter=bm.begin(); iter != bm.end(); ++iter){
	// 	cout << iter->first << ":" << iter->second << endl;
	// }
	string alphabets = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < alphabets.length(); i += 1){
		if (am[alphabets[i]] && bm[alphabets[i]]) return true;
	}
	return false;
}


int main(void){
	//solve("lavee singh", "shruti singh");
	int t;
	string a, b, ans;
	cin >> t;
	while (t--){
		cin >> a;
		cin >> b;
		//cout << "Solve is: " << solve(a, b) << endl;
		ans = solve(a, b) ? "Yes" : "No";
		cout << ans << endl;
	}
}