#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

string solve(string a, int k){
	int freq[26];
	fill_n(freq, 26, 0);
	for (char x: a){
		freq[x-'a'] += 1;
	}
	// for (int i = 0; i < 26; i += 1){
	// 	cout << freq[i] << " ";
	// }
	// cout << endl;
	string fsegment = "";
	for (int i = 0; i < 26; i += 1){
		if(freq[i]%k) {
			// cout << a[i] << " is not good" << endl;
			return "-1";
		}
		int count= freq[i]/k;
		for (int j = 0; j < count; j += 1){
			fsegment += i+'a';
		}
	}
	// cout << "The first segment is: " << fsegment << endl;
	string ans = "";
	for (int i = 0; i < k; i += 1){
		ans += fsegment;
	}
	return ans;
}


int main(void){
	int k;
	string a;
	cin >> k;
	cin >> a;
	cout << solve(a, k) << endl;
}