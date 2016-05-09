#include <iostream>

using namespace std;

int kmp(string a, string pat){
	// compute lps array
	int n = a.length();
	int m = pat.length();
	int i=1,j,len=0;
	int lps[m];
	lps[0] = 0;
	while (i<m){
		if (pat[i] == pat[len]){
			len += 1;
			lps[i] = len;
			i += 1;
		}else{
			if (len != 0){
				len = pat[len-1];
			}else{
				lps[i] = 0;
				i += 1;
			}
		}
	}
	i = 0;
	j = 0;
	int ans = 0;
	while (i < n){
		if (a[i] == pat[j]){
			i += 1;
			j += 1;
		}
		if (j == m){
			ans += 1;
			j = lps[j-1];
		}else if(i < n && a[i] != pat[j]){
			if (j != 0){
				j = lps[j-1];
			}else{
				i += 1;
			}
		}
	}
	return ans;
}

int main(void){
	int t;
	string a, pat;
	int sv, svj;
	cin >> t;
	while (t--){
		cin >> a;
		sv = kmp(a, "SUVO");
		svj = kmp(a, "SUVOJIT");
		sv -= svj;
		cout << "SUVO = " << sv << ", SUVOJIT = " << svj << endl;
	}
}