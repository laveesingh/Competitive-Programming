#include <iostream>
#include <map>

using namespace std;

int main(void){
	map<string, int> store;
	int n;
	cin >> n;
	string name;
	for (int i = 0; i < n; i += 1){
		cin >> name;
		if(!store[name]){
			cout << "OK" << endl;
			store[name] += 1;
		}else{
			cout << name << store[name] << endl;
			store[name] += 1;
		}
	}
}