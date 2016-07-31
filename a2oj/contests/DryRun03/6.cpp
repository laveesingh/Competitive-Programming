#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string solve(string a){
	int freq[26];
	fill_n(freq, 26, 0);

	for (int i = 0; i < a.length(); i += 1){
		if(islower(a[i])){
			freq[a[i]-'a'] = 1;
		}else{
			freq[a[i]-'A'] = 1;
		}
	}
	for (int i = 0; i < 26; i += 1){
		if (freq[i] == 0) return "NO";
	}
	return "YES";
}

int main(void){
	int n;
	string a;
	cin >> n;
	cin >> a;
	cout << solve(a) << endl;
}