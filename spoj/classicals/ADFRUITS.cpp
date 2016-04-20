#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

string lcs(string a, string b){
	int n = a.length();
	int m = b.length();
	int dp[n+1][m+1];
	for (int i = 0; i <= n; i += 1){
		for (int j = 0; j <= m; j += 1){
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	int i = n, j = m;
	string ans = "";
	while (i > 0 || j > 0){
		if (a[i-1] == b[j-1]){
			ans = a[i-1]+ans;
			i -= 1;
			j -= 1;
		}else{
			if (dp[i-1][j] >= dp[i][j-1]){
				i -= 1;
			}else{
				j -= 1;
			}
		}
	}
	return ans;

}

int main(void){
	string t;
	while (getline(cin, t)){
		string a="", b="";
		bool flag = false;
		for (int i = 0; i < t.length(); i += 1){
			if (t[i] == ' ') flag = true;
			if (flag == false) a += t[i];
			else if(flag == true && t[i] != ' ') b += t[i];
		}
		// cin >> a;
		// cin >> b;
		// cout << lcs(a, b) << endl;
		string l = lcs(a, b);
		// map<char, int> d;
		string ans = "";
		int i = 0, j = 0, k = 0;
		while (i < a.length() || j < b.length() || k < l.length()){
			while (i < a.length()){
				if (k < l.length()){
					if (a[i] != l[k]){
						ans += a[i];
						i += 1;
					}else{
						break;
					}
				}else{
					ans += a[i];
					i += 1;

				}
			}
			while (j < b.length()){
				if(k < l.length()){
					if(b[j] != l[k]){
						ans += b[j];
						j += 1;
					}else{
						break;
					}
				}else{
					ans += b[j];
					j += 1;
				}
			}
			if (k < l.length()) {
				ans += l[k];
				i += 1;
				j += 1;
				k += 1;
			}
		}
		cout << ans << endl;
	
	}
}