#include <iostream>
#include <algorithm>

using namespace std;

bool win(string a){
	for (int i = 0; i < a.length(); i +=1){
		if (a[i] == '0') return true;
	}
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	int n, d;
	cin >> n >> d;
	string a[d];
	for (int i = 0; i < d; i += 1){
		cin >> a[i];
	}
	int total = 0, mtotal = 0;
	for (int i = 0; i < d; i += 1){
		if(win(a[i])){
			total += 1;
			mtotal = max(mtotal, total);
		}else {
			total = 0;
		}
	}
	cout << mtotal << endl;
}