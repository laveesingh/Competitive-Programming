#include <map>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

map<int, int> store;

int i = 0;

int sum(string a){
	int s = 0;
	for (char x : a){
		int xi = (int)x-48;
		s += xi*xi;
	}
	return s;
}

bool solve(int n){
	string a;
	stringstream ss;
	ss << n;
	ss >> a;
	int s = sum(a);
	if (s == 1) return true;
	if (store[s]) return false;
	store[s] = 1;
	return solve(s);	
}

int main(void){
	int n;
	cin >> n;
	bool ans = solve(n);
	if (ans){
		cout << store.size()+1 << endl;
	}else{
		cout << -1 << endl;
	}
}