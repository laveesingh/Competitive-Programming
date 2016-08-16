/*input
3
4
1 1 1 1
4
3 0 0 0
4
0 0 0 2
*/

#include <bits/stdc++.h>

using namespace std;

#define init(a, n) a.find(n) != a.end()

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		int isM[n];
		int isNM[n];
		fill_n(isM, n, 0);
		fill_n(isNM, n, 0);
		for (int i = 0; i < n; i += 1){
			if (isM[i] or isNM[i]){
				// do nothing
			}else{
				int j = i;
				set<int> st1;
				stack<int> st;
				while(true){
					// cout << "j " << j << endl;
					if (isM[j]){
						break;
					}else if (init(st1, j)){
						isM[j] = 1;
						int temp = st.top();
						st.pop();
						while (temp != j and !st.empty()){
							// cout << "temp " << temp << endl;
							isM[temp] = 1;
							isNM[temp] = 0;
							temp = st.top();
							st.pop();
						}
						break;
					}else if(isNM[j]){
						break;
					}else{
						st1.insert(j);
						st.push(j);
						isNM[j] = 1;
						j = (j+1+a[j])%n;
					}
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i += 1){
			if (isM[i] == 1){
				cnt++;
			}
		}
		cout << cnt << endl;
	}	
}