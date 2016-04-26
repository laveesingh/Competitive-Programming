#include <map>
#include <iostream>

using namespace std;

string seq[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};

void solve(string a, int n){
	map<string, int> store;
	string cur = "";
	for (int i = 0; i < a.length(); i += 1){
		string s = a.substr(i,1);
		cur += s;
		for (string x: seq){
			if (cur == x){
				store[x] += 1;
				cur = cur.substr(1,2);
			}
		}
	}
	cout << n << " ";
	for(string x: seq){
		cout << store[x] << " ";
	}
	cout << endl;
}

int main(void){
	int t, n;
	string a;
	cin >> t;
	while (t--){
		cin >> n;
		cin >> a;
		solve(a, n);
	}
}
