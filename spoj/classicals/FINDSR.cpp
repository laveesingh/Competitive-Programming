#include <bits/stdc++.h>

using namespace std;

int *lps;

void LPS(string a){
	int n = a.length();
	lps = new int[n];
	lps[0] = 0;
	int len = 0, i = 1;
	while (i < n){
		if(a[i]==a[len]){
			lps[i++] = ++len;
		}else{
			if (len != 0){
				len = lps[len-1];
			}else{
				lps[i++] = 0;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	
}