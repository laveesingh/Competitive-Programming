#include <iostream>
#include <string.h>

using namespace std;

string solve(string a){
	int lc = 0, uc = 0, n =a.length();
	for (int i = 0; i < n; i += 1){
		if(islower(a[i])){
			lc += 1;
		}else{
			uc += 1;
		}
	}
	if(lc >= (a.length()+1)/2){
		for(int i = 0; i < n; i += 1){
			a[i] = tolower(a[i]);
		}
	}else{
		for(int i = 0; i < n; i += 1){
			a[i] = toupper(a[i]);
		}
	}
	return a;
}

int main(void){
	string a;
	cin >> a;
	cout << solve(a) << endl;
}