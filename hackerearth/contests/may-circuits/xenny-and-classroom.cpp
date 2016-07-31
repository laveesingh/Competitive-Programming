#include <iostream>

using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string a;
		cin >> a;
		
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < 2*n; i += 2){
			if(a[i] == 'B') ans1 += 1;
		}
		for(int i = 0; i < 2*n; i += 2){
			if(a[i] == 'G') ans2 += 1;
		}
		if(ans1 < ans2){
			cout << ans1 << endl;
		}else{
			cout << ans2 << endl;
		}

	}
}