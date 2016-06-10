#include <iostream>

using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		if(n%6){
			cout << "Chef" << endl;
		}else{
			cout << "Misha" << endl;
		}
	}
}