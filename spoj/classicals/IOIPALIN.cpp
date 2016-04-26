#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int lcs(string a, string b){
	int n = a.length();
	int m = b.length();
	int dp[2][m+1];
	// cout << "Built a dp table." << endl;
	dp[0][0] = 0;
	dp[1][0] = 0;
	for (int i = 0; i <= m; i += 1){
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i += 1){
		for (int j = 1; j <= m; j += 1){
			if (a[i-1] == b[j-1]){
				dp[i%2][j] = dp[(i+1)%2][j-1]+1;
			}else{
				dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j-1]);
			}
		}
	}
	// cout << "Filled the dp table." << endl;
	// for (int i = 0; i < 2; i += 1){
	// 	for (int j = 0; j < m+1; j += 1){
	// 		cout << dp[i][j] << " " ;
	// 	}
	// 	cout << endl;
	// }	
	return dp[n%2][m];

}

int lcs(char *a, int n){
	int dp[2][n];

	for (int i = n-1; i >= 0; --i){
		for (int j = i+1; j < n; ++j){
			if (a[i]==a[j]){
				dp[i%2][j] = dp[(i+1)%2][j-1];
			}else{
				dp[i%2][j] = 1+min(dp[(i+1)%2][j], dp[i%2][j-1]);
			}
		}
	}
	return dp[n%2][n-1];

}

int solve(char *a, int n){
	// cout << "Reversing the string." << endl;
	// string b = "";
	// for (int i = a.length()-1; i >= 0; i -= 1){
	// 	b.push_back(a[i]);
	// }
	// cout << "Reversed the string. Now finding lcs." << endl;
	// cout << "B: " << b << endl;
	int lol = lcs(a, n);
	// cout << "Length of the lcs: " << lol << endl;
	return n-lol;
}

// int main(void){
// 	int n;
// 	scanf("%d",&n);
// 	string a;
// 	char *b = new char[n];
// 	scanf("%s",b);
// 	// a = b;
// 	// cin >> a;
// 	// cin >> n;
// 	// string a;
// 	// cin >> a;
// 	// a = b;
// 	printf("%d\n",solve(b, n));
// }

int main() {
  char *s;
  short i, j, n, **w;

  scanf("%hd", &n);

  s = new char[n];
  scanf("%s", s);

  w = new short*[2];
  for (i = 0; i < 2; ++i) {
    w[i] = new short[n];
    for (j = 0; j < n; ++j) {
      w[i][j] = 0;
    }
  }

  for (i = n - 1; i >= 0; --i) {
    for (j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) {
        w[i % 2][j] = w[(i + 1) % 2][j - 1];
      } else {
        w[i % 2][j] = 1 + min(w[i % 2][j - 1], w[(i + 1) % 2][j]);
      }
    }
  }
  printf("%hd\n", w[0][n - 1]);

  return 0;
}