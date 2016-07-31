#include <iostream>
#include <cstdio>

using namespace std;

bool iszero(string a){
	for (int i = 0; i < a.length(); i += 1){
		if (a[i] == '0') return true;
	}
	return false;
}

bool isone(string a){
	for (int i = 0; i < a.length(); i += 1){
		if(a[i] == '1') return true;
	}
	return false;
}

int main(void){
	int t;
	string a;
	string b;
	cin >> t;
	while(t--){
		cin >> a;
		cin >> b;
		if(!iszero(a) || !isone(a)){
			cout << "Unlucky Chef" << endl;
		}else{
			cout << "Lucky Chef" << endl;
			int c1 = 0, c2 = 0;
			for (int i = 0; i < a.length(); i += 1){
				if(a[i]=='1' && b[i] == '0'){
					c1 += 1;
				}else if(a[i] == '0' && b[i] == '1'){
					c2 += 1;
				}
			}
			cout << (c1 > c2 ? c1 : c2) << endl;
		}
	}
}