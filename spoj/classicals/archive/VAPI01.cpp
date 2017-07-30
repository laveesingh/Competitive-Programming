#include <iostream>
#include <cstring>
#include <map>

using namespace std;

// int keys[26];

int main(void){
	int t, n;
	cin >> t;
	string a;

	while(t--){
		
		// memset(keys, 0, 26);
		map<char, int> keys;
		cin >> n;
		cin >> a;
		int count = 0;
		for (int i = 0; i < 2*n-2; i += 1){
			if (i%2){
				if(keys[tolower(a[i])]) {
					// cout << tolower(a[i]) << endl;
					keys[tolower(a[i])] -= 1;
				}
				else count += 1;
			}else{
				keys[a[i]] += 1;
			}
		}
		cout << count << endl;
	}
}