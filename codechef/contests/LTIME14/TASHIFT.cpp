/*input
5
ccadd
bddcc
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string a, b;
	cin >> b >> a;
	a = a + a;
	a = a.substr(0,2*n-1);
	// cout << "a: " << a << endl;
	int lps[2*n-1], len = 0, i = 1;
	fill_n(lps, 2*n-1, 0);
	if (a[0] == b[0]){
		lps[0] = 1;
		len = 1;
	}else{
		lps[0] = 0;
	}
	while(i < a.length() and len < b.length()){
		// cout << "i : " << i << " len: " << len << endl;
		if(a[i] == b[len]){
			lps[i++] = ++len;
		}else{
			if(len != 0){
				len = lps[len-1];
				if (len == lps[len-1]){
					lps[i++] = 0;
					len = 0;
				}
			}else{
				lps[i++] = 0;
			}
		}
	}
	// cout << "lps array " << endl;
	// for (int i = 0; i < 2*n-1; i += 1){
	// 	cout << lps[i] << " ";
	// }
	// cout << endl;
	int ind = max_element(lps, lps+(2*n-1))-lps;
	// cout << "ind: " << ind << endl;
	if (lps[ind] == 0){
		cout << 0 << endl;
	}else{
		cout << (ind-lps[ind]+1) << endl;
	}

}
