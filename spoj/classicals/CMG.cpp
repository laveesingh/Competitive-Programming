/*input
2

6

A 10

A 5

Q

A 100

R

Q

6

A 5

Q

R

Q

R

R
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int j = 1; j <= t; j += 1){
		multiset<int> basket;
		stack<int> latest;
		int n;
		cin >> n;
		char type;
		int x;
		cout << "Case " << j << ":" << endl;
		for (int i = 0; i < n; i += 1){
			cin >> type;
			if (type == 'A'){
				cin >> x;
				basket.insert(x);
				latest.push(x);
			}else if(type == 'R'){
				if (!latest.empty()){
					int temp = latest.top();
					latest.pop();
					basket.erase(temp);
				}
			}else{
				if (latest.empty()){
					cout << "Empty" << endl;
				}else{
					cout << *(basket.rbegin()) << endl;
				}
			}
		}
	}	
}