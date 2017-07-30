#include <iostream>

using namespace std;

void solve(){
	long long int ans, next;
	char op;

	cin >> ans;
	while (true){
		cin >> op;
		if (op == '=') break;
		cin >> next;
		if (op == '+'){
			ans += next;
		}else if(op == '-'){
			ans -= next;
		}else if(op == '*'){
			ans *= next;
		}else{
			ans /= next;
		}
	}
	cout << ans << endl;
}

int main(void){
	int t;
	cin >> t;
	while (t--){
		solve();
	}
}