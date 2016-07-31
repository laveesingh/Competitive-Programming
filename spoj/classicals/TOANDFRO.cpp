#include <iostream>

using namespace std;

string reversed(string a){
	string ans = "";
	for (int i = a.length()-1; i >= 0; i -= 1){
		ans.push_back(a[i]);
	}
	return ans;
}

void solve(int n, string a){
	int m = a.length()/n;
	string arr[m];
	string ans = "";
	for (int i = 0; i < m; i += 1){
		if (i%2){
			arr[i] = reversed(a.substr(i*n,n));
		}else{
			arr[i] = a.substr(i*n,n);
		}
	}
	for (int j = 0; j < n; j += 1){
		for (int i = 0; i < m; i +=1){
			ans += arr[i][j];
		}
	}
	cout << ans << endl;
}

int main(void){
	int n;
	string a;
	while (1){
		cin >> n;
		if (n == 0) break;
		cin >> a;
		solve(n,a);
	}
}