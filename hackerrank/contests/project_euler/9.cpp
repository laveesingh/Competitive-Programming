#include <iostream>

using namespace std;

bool isint(float a){
	if(a - (int)a == 0) return true;
	return false;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		for (int a = 1; a < n+1; a += 1){
			float b = (float)(n*n - 2*a*n)/(float)(2*n-2*a);
			// cout << b << " " << isint(b) << endl;
			if(isint(b) && b > 0){
				int c = n-a-(int)b;
				// cout << a << " " << b << " " << c << endl;
				ans = max(ans, (a*(int)b*c));
			}
		}
		if(ans == 0){
			cout << -1 << endl;
		}else{
			cout << ans << endl;
		}
	}
}