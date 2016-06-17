#include <iostream>
using namespace std;

int main(void){
	int t,a[] = {0, 1, 0, 0, 1, 0, 1, 0, 1, 2};
	cin >> t;
	string s;
	int n;
	while(t--){
		cin >> n >> s;
		int cost = 0;
		for (int i = 0; i < s.length(); i += 1){
			cost += a[s[i]-'0'];
		}
		cout << cost << endl;
	}
}