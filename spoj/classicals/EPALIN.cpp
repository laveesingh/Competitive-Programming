#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

void Print(int a[], int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

string reversed(string a){
	reverse(a.begin(), a.end());
	return a;
}

// string solve(string a){
// 	string b = reversed(a);
// 	int lps[b.length()];
// 	int len = 0, i = 0;
// 	while (i < b.length()){
// 		if (a[i] == b[len]){
// 			lps[i++] = ++len;
// 		}else{
// 			if(len != 0){
// 				len = lps[len-1];
// 			}else{
// 				lps[i++] = 0;
// 			}
// 		}
// 	}
// 	// Print(lps,b.length());
// 	int trimmed = a.length()-lps[a.length()-1]-1;

// 	while(trimmed >= 0){
// 		a.push_back(a[trimmed--]);
// 	}
// 	return a;
// }

void solve(char a[]){
	int n = 0;
	// cout << "value of n is " << n << endl;

	while (a[n] != '\0'){
		n += 1;
	}
	// cout << "value of n is " << n << endl;
	for (int i = 0; i < n; i += 1){
		printf("%c",a[i]);
	}
	// cout << endl << "We printed the initial string" << endl;
	int lps[n];
	int len = n-1;
	int i = 0;
	// cout << "Now going to compute lps array" << endl;
	while(i<n){
		if(a[i] == a[len]){
			lps[i++] = n - --len - 1 ;
		}else{
			if (n-1-len != 0){
				len = n-1-lps[n-1-len-1];
			}else{
				lps[i++] = 0;
			}
		}
	}
	// cout << "LPS array computed " << endl;
	int trimmed = n - lps[n-1] - 1;
	while(trimmed >= 0){
		printf("%c",a[trimmed--]);
	}
	printf("\n");
}

int main(void){
	char a[100001];
	while (scanf("%s",a)==1){
		// if (a[0] == '\0') break;
		solve(a);
	}
}