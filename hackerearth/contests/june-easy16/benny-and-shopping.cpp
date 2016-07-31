#include <iostream>
#include <algorithm>

using namespace std;

string solve(string a){
	string b = a.substr(find(a.begin(), a.end(), '$')-a.begin());
	string ans = "$";
	for (int i = 0; i < b.length(); i += 1){
		if (ans.length() == 1){

			if (b[i] > '0' && b[i] <= '9'){
				ans.push_back(b[i]);
			}
		}else{
			if(b[i] >= '0' && b[i] <= '9'){
				ans.push_back(b[i]);
			}
		}
		if ((b[i] < '0' || b[i] > '9') && b[i] != ' '){
			cout << "Breaking because of " << b[i] << endl;
			break;
		}
	}
	return ans;
}

int main(void){
	string a;
	int t;
	cin >> t;
	while(t--){
		getline(cin, a);
		cout << solve(a) << endl;
	}
}