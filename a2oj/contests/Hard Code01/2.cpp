#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> solve(int n){
	vector<int> ans;
	string::size_type sz;
	while(n>0){
		// cout << "n = " << n << endl;
		string ns = to_string(n);
		stringstream curs;
		for(int i = 0; i < ns.length(); i += 1){
			if(ns[i] > '0'){
				// curs.push_back('1');
				curs << 1;
			}else{
				// curs.push_back('0');
				curs << 0;
			}
		}
		int curn;
		curs >> curn;
		n -= curn;
		ans.push_back(curn);
	}
	return ans;
}

int main(void){
	int n;
	cin >> n;
	vector<int> ans = solve(n);
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i += 1){
		cout << ans[i] << " ";
	}
	cout << endl;
}