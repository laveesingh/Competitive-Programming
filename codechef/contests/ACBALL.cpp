#include <iostream>

using namespace std;

int main(void){
	int t;
	cin >> t;
	string x, y,z="";
	while(t--){
		cin >> x >> y;

		for (int i = 0; i < x.length(); i += 1){
			if (x[i] == y[i]){
				if(x[i] == 'B') z.push_back('W');
				else z.push_back('B');
			}else{
				z.push_back('B');
			}
		}
		cout << z << endl;
	}
}