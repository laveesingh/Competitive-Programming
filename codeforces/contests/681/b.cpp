#include <iostream>
#include <map>

using namespace std;

map<int, int> store;
int a = 1234567, b = 123456, c = 1234;

bool solve(int n){
	for (int i = 0; i < n/a+1; i += 1){
		for(int j = 0; j < n/b+1; j += 1){
			if((n-i*a-j*b) >= 0 && (n-i*a-j*b)%c==0){
				return true;
			}
		}
	}
	return false;
}

int main(void){
	int n;
	cin >> n;
	if(solve(n)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}