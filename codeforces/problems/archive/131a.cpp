#include <iostream>
#include <string>

using namespace std;

string change_case(string a){
	string temp = "";
	for (char x: a){
		if (isupper(x)){
			temp += string(1, tolower(x));
		}else{
			temp += string(1, toupper(x));
		}
	}
	return temp;
}

bool iscap(string a){
	for (int i = 1; i < a.length(); i += 1){
		if (islower(a[i])) return false;
	}
	return true;
}

string solve(string a){
	if (iscap(a)){
		return change_case(a);
	}else{
		return a;
	}
}



int main(void){

	string a;
	cin >> a;
	cout << solve(a) << endl;

}