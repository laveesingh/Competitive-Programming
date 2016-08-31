/*input
1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
abc
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int a[26];
	for (int i = 0; i < 26; i += 1){
		cin >> a[i];
	}	
	string word;
	cin >> word;
	int width = word.length();
	int h = 0;
	for (char x: word){
		h = max(h, a[x-'a']);
	}
	cout << h*width << endl;
}