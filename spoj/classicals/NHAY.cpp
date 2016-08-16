/*input
2
na
banananobano
6
foobar
foo
9
foobarfoo
barfoobarfoobarfoobarfoobarfoo
*/


// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int *lps;

void LPS(string a){
	int n = a.length();
	lps = new int[n];
	lps[0] = 0;
	int i = 1, len = 0;
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
	int n;
	while(cin >> n){
		string a, b;
		cin >> a >> b;
		LPS(a);
		int i = 0, j = 0;
		vector<int> inds;
		while (i < b.length()){
			if(a[j] == b[i]){
				j++;
				i++;
				if (j == a.length()){
					inds.push_back(i-j);
					j = lps[j-1];
				}
			}else{
				if(j != 0){
					j = lps[j-1];
				}else{
					i++;
				}
			}
		}
		// cout << "Here's the lps array" << endl;
		// for (int i = 0; i < n; i += 1){
		// 	cout << lps[i] << " ";
		// }
		// cout << endl;
		if(inds.size()){
			// cout << "Pring coming" << endl;
			for (i = 0; i < inds.size(); i ++){
				cout << inds[i] << endl;
			}
		}else{
			cout << endl;
		}
	}
}
