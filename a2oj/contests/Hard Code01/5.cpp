#include <iostream>

using namespace std;

int main(void){
	string a;
	cin >> a;
	int i = 1;
	int flag = 0;
	bool ans = false;
	while (i < a.length()){
		if(a[i] == 'B' && a[i-1] == 'A'){
			if(flag == 0){
				flag = 1;
				i += 2;
			}else{
				i += 1;
			}
		}else if(a[i] == 'A' && a[i-1] == 'B'){
			if(flag == 1){
				ans = true;
			}
			i += 1;
		}else{
			i++;
		}
		
	}
	i = 1;
	flag = 0;
	while(i < a.length()){
		if(a[i] == 'A' && a[i-1] == 'B'){
			if(flag == 0){
				flag = 1;
				i +=2;
			}else{
				i += 1;
			}
		}else if(a[i] == 'B' && a[i-1] == 'A'){
			if(flag == 1){
				ans = true;
			}
			 i += 1;
		}else{
			i++;
		}
	}
	if(ans){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}