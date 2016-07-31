#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	string name;
	int before, after;
	bool flag = false;
	for (int i = 0; i < n ; i += 1){
		cin >> name >> before >> after;
		if(after > before && before >= 2400){
			flag = true;
		}
	}
	if(flag == true){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}