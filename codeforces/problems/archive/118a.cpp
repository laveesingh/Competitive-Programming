#include <iostream>
#include <ctype.h>
using namespace std;

bool isVowel(char s){
	string vostr = "aeiouyAEIOUY";
	for (char x: vostr){
		if (x == s) return true;
	}
	return false;
}

int main(void){
	string a ;
	cin >> a;
	for (int i = a.length()-1; i >= 0; i -= 1){
		if(isVowel(a[i])) a.replace(i, 1, "");
		else a.replace(i, 1, string(1, tolower(a[i])));
	}
	for (int i = a.length()-1; i >= 0; i -= 1){
		a.insert(i, ".");
	}
	cout << a << endl;
}