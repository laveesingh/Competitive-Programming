#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int solve(string a){
	int ans = 0;
	while (a.length() > 0){
		// cout << "Loop starts:" << endl;
		if (a.find("{}") != string::npos)
			a.replace(a.find("{}"),sizeof("{}")-1, "");
		if (a.length()>0 && a.find("{}")==string::npos){
			if (a[0] == '}' && a[a.length()-1]=='{'){
				ans += 2;
				a[0] = '{';
				a[a.length()-1] = '}';
			}else if(a[0] == '}'){
				ans += 1;
				a[0] = '{';
			}else if(a[a.length()-1] == '{'){
				ans += 1;
				a[a.length()-1] = '}';
			}
		}
	}
	return ans;
}

int main(void){
	string a;
	int i = 1;
	while (1){
		cin >> a;
		if (a[0] == '-') break;
		printf("%d. %d\n", i, solve(a));
		i += 1;
	}
}
// int main(void){
// 	string a = "}{";
// 	a.replace(a.find("{}"), sizeof("{}")-1, "");
// 	cout << a; 
// }