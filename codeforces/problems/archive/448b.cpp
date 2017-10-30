#include <iostream>
#include <algorithm>

using namespace std;

string sorted(string a){
	sort(a.begin(), a.end());
	return a;
}

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int lcs(string a, string b){
	int n = a.length();
	int m = b.length();
	int dp[n+1][m+1];
	for (int i = 0; i <= n; i += 1){
		for (int j = 0; j <= m; j += 1){
			if (i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	// cout << "n: " << n << " m: " << m << endl;
	// for (int i = 0; i<= n; i +=1 ){
	// 	for (int j = 0; j <= m; j += 1){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << dp[n+1][m+1] << endl;
	return dp[n][m];
}

string solve(string s, string t){
	int freqs[26]={0};
	int freqt[26]={0};
	for (char x : s){
		freqs[x-97] += 1;
	}
	for (char x: t){
		freqt[x-97] += 1;
	}
	for (int i = 0; i < 26; i += 1){
		if (freqt[i] > freqs[i]) return "need tree";
	}
	if (s.length() == t.length()){
		if (sorted(s) != sorted(t)){
			return "need tree";
		}else{
			return "array";
		}
	}
	if (lcs(s,t) == t.length()){
		return "automaton";
	}
	return "both";
}

int main(void){
	string s, t;
	cin >> s >> t;
	cout << solve(s, t) << endl;

}