#include <iostream>

using namespace std;

int main(void){
	string a;
	cin >> a;
	int j = 0;
	string h = "hello";
	for (int i = 0; i < a.length(); i += 1){
		if(j < 5 && a[i]==h[j]){
			j++;
		}
	}
	if(j >= 5){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}