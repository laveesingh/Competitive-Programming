#include <iostream>
#include <algorithm>

using namespace std;

int *a, *b, *ans, *fact;

void mult(){
	ans = new int[158];
	fill_n(ans, 158, 0);
	for (int i = 157; i >= 0; i -= 1){
		int ind = i;
		int carry = 0, temp;
		for (int j = 157; j >= 0; j -= 1){
			temp= (carry+b[i]*a[j]+ans[ind]);
			ans[ind] = temp%10;
			carry = temp/10;
			ind -= 1;
		}
	}
	
}

void solve(int n){
	fact = new int[158];
	a = new int[158];
	b = new int[158];
	fill_n(fact, 158, 0);
	fact[157] = 1;
	for (int i = 2; i <= n; i += 1){
		for (int ii = 0; ii < 158; ii += 1){
			a[ii] = fact[ii];
		}
		int k = i;
		for (int j = 157; j >= 0; j -= 1){
			b[j] = k%10;
			k /= 10;
		}
		mult();
		for (int ii = 0; ii < 158; ii += 1){
			fact[ii] = ans[ii];
		}
	}
	int flag = 0;
	for (int i = 0; i < 158; i += 1){
		if (flag == 0 && ans[i] == 0){
		}else{
			flag = 1;
			cout << ans[i];
		}
	}
	cout << endl;
}


int main(void){

	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		if (n == 0) cout << 1 << endl;
		else if ( n == 1 || n == 2) cout << n << endl;
		else solve(n);
	}
}