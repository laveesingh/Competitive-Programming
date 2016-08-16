/*input
2
3
aaa
12
aabaabaabaab
*/

#include <bits/stdc++.h>

using namespace std;

int *lps;

void Lps(int n, string a){
	int len = 0;
	int i = 1;
	lps = new int[n];
	lps[0] = 0;
	while (i < n){
		if(a[i] == a[len]){
			lps[i++] = ++len;
		}else{
			if(len != 0){
				len = lps[len-1];
			}else{
				lps[i++] = 0;
			}
		}
	}
}


int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int cs = 0;
	while(t--){
		cs++;
		int n;
		cin >> n;
		string a;
		cin >> a;
		Lps(n, a);
		// cout << "Here's the lps array to " << a << endl;
		// for (int i = 0 ; i < n; i += 1){
		// 	cout << lps[i] << " " ;
		// }
		// cout << endl;
		cout << "Test case #" << cs << endl;
		for (int i = 1; i < n; i += 1){
			// cout << lps[i] << " " << i+1 << endl;
			if(lps[i] != 0 and (i+1)%(i+1-lps[i]) == 0){

				cout << i+1 << " " << ((i+1)/(i+1-lps[i])) << endl;
			}
		}
	}	
}
