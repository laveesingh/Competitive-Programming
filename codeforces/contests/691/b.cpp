#include <bits/stdc++.h>

using namespace std;

int main(void){
	map<char, char> mirror;
	mirror['b'] = 'd';
	mirror['d'] = 'b';
	mirror['p'] = 'q';
	mirror['q'] = 'p';
	string rest = "ovwxAHIMOTUVWXY";
	for (char s : rest){
		mirror[s] = s;
	}
	string pal;
	int t;
	cin >> t;
	while(t--){
		
		cin >> pal;
		int n = pal.length();
		bool flag = true;
		for(int i = 0; i < n; i += 1){
			char mir = pal[n-i-1];
			if(mirror.find(pal[i]) != mirror.end() && mirror[pal[i]] == mir){
				// do nothing
			}else{
				flag = false;
				break;
			}
		}
		cout << (flag == true ? "TAK" : "NIE") << endl;
	}
}