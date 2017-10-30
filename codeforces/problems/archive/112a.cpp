#include <iostream>
#include <string>

using namespace std;

int compare(string a, string b){
	for (int i = 0; i < a.length(); i += 1){
		if (tolower(a[i]) < tolower(b[i])){
			return -1;
		}else if(tolower(a[i]) > tolower(b[i])){
			return 1;
		}
	}
	return 0;
}

int main(void){
	string a, b;
	cin >> a >> b;
	cout << compare(a, b) << endl;
}