/*input
2 3 4 5 1 1 1 1
3 6 9 0 1 2 3 4
-1 -1 -1 -1 -1 -1 -1 -1
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	
	while(1){
		int s[4], d[4];
		for (int i = 0; i < 4; i += 1){
			cin >> s[i];
		}
		for (int i = 0; i < 4; i += 1){
			cin >> d[i];
		}
		if (s[0] == -1) break;
		int start = 0, end = 10001, x = -1;
		int req[4];
		while(start <= end){
			int negFlag = 0;
			if(x == (start + (end-start)/2)) break;
			x = start + (end-start)/2;
			for (int i = 0; i < 4; i += 1){
				if(d[i]*x - s[i] < 0){
					negFlag = 1;
				}else{
					req[i] = d[i]*x - s[i];
				}
			}
			if (negFlag){
				start = x+1;
			}else{
				end = x;
			}
		}
		for (int i = 0; i < 4; i += 1){
			cout << req[i] << " " ;
		}
		cout << endl;
	}
}
