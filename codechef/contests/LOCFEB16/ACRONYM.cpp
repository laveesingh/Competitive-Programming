#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;

bool isAc(string a){
	if (a.length() < 2) return false;
	for (int i = 0; i < a.length(); i += 1) 
		if (!isupper(a[i])) return false;
	return true;
}

vector<string> split(string a){
	vector<string> v;
	string temp = "";
	for(int i = 0; i < a.length(); i += 1){
		if (a[i] == ' '){
			v.push_back(temp);
			temp = "";
		}
		else temp += a[i];
	}
	if(temp != "") v.push_back(temp);
	
	return v;
}

int main(void){
	string a;
	getline(cin, a);
	vector<string> v = split(a);
	int count = 0;
	for (int i = 0; i < v.size(); i += 1){
		if (isAc(v[i])){
			count += 1;
		}
	}
	cout << count << endl;
}