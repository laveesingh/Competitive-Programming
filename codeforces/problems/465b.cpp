#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i+= 1){
		cin >> a[i];
	}
	int ans = 0;
	bool flag = false;
	for (int i = 0; i < n; i += 1){
		if(flag == false && a[i]==1){
			ans += 1;
			flag = true;
		}else if(flag == true && a[i]==1){
			if(a[i-1] == 1){
				ans += 1;
			}else{
				ans += 2;
			}
		}	
	}
	cout << ans << endl;
}