#include <iostream>

using namespace std;

int abs(int a){
	if (a < 0) return -a;
	return a;
}

int main(void){
	int ans = 0, temp;
	for (int i = 0; i < 10; i += 1){
		cin>>temp;
		if(ans + temp > 100){
			if(abs(ans-100) < abs(ans+temp-100)){
				cout << ans << endl;
				return 0;
			}else{
				cout << ans+temp << endl;
				return 0;
			}
		}else if(ans + temp == 100){
			cout << 100 << endl;
			return 0;
		}else{
			ans += temp;
		}
	}
	cout << ans << endl;
}