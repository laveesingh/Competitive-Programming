#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void){
	int t, n;
	string temp;
	cin >> t;
	while(t--){
		cin >> n;
		cin.ignore();
		vector<string> a(n);
		for (int i = 0; i < n;i += 1){
			// cout << "Enter : " << i << "th element." << endl;
			getline(cin, temp);

			a[i] = temp;
		}
		sort(a.begin(), a.end());
		map<string, int> freq;
		for (string s : a){
			freq[s] += 1;
		}
		for (map<string, int>::iterator it = freq.begin(); it != freq.end(); ++it){
			cout << it -> first << " " << it -> second << endl;
		}
	}
}