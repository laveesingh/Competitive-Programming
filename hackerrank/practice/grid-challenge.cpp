#include <iostream>
#include <algorithm>

using namespace std;

char **a;

string solve(){
	int n;
	cin >> n;
	a = new char*[n];
	for (int i = 0; i < n; i+= 1){
		a[i] = new char[n];
	}
	char x;
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j += 1){
			cin >> x;
			a[i][j] = x;
		}
	}
	for (int i = 0; i < n; i += 1){
		sort(a[i],a[i]+n);
	}
	// for (int i = 0; i < n; i += 1){
	// 	for (int j = 0; j < n; j += 1){
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 0; i < n; i += 1){
		for (int j = 1; j < n; j += 1){
			if (a[j][i] < a[j-1][i]) return "NO";
		}
	}
	return "YES";

}
int main(void){
	int t;
	cin >> t;
	while (t--){
		cout << solve() << endl;
	}
}