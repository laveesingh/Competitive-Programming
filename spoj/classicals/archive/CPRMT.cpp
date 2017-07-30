#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	string a;
	string b;
	while(cin>>a && cin >> b){
		// cin >> a;
		// cin >> b;
		int freqa[26];
		int freqb[26];
		fill_n(freqa, 26, 0);
		fill_n(freqb, 26, 0);
		for (char x: a){
			freqa[x-'a'] += 1;
		}
		for (char x: b){
			freqb[x-'a'] += 1;
		}
		string ans="";
		for (int i = 0; i < 26; i += 1){
			int t = min(freqa[i], freqb[i]);
			for(int j = 0; j < t; j += 1){
				ans.push_back(i+'a');
			}
		}
		cout << ans << endl;
	}
}