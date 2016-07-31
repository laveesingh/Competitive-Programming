#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		float ans= 0.0;
		for (int i = 1; i <= n; i += 1){
			ans += (1.0)/(float)i;
		}
		ans *= n;
		cout << fixed;
		cout << setprecision(2) << ans << endl;
	}
}