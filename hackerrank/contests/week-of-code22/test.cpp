/*input
9
+ 1
+ 1
+ 2
-
+ 1
-
-
-
+ 3
*/

#include <bits/stdc++.h>

using namespace std;

void print(vector<int> a){
	for (int x: a){
		cout<< x << " ";
	}
	cout << endl;
}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	char type;
	int x;
	map<vector<int>,int> store;
	vector<int> seq;
	int len = 0;
	for (int i = 0; i < n; i += 1){
		cin >> type;
		if (type == '+'){
			cin >> x;
			seq.push_back(x);
			len++;
		}else{
			seq.pop_back();
			len--;
		}
		if (store.find(seq) != store.end()){
			cout << store[seq] << endl;
		}else{
			if (len == 0 || len == 1){
				store[seq] = 0;
			}
			bool flag = false;
			for (int k = len-1; k >= 0; k -= 1){
				bool equal=true;
				for (int cmp = 0; cmp < k; cmp++){
					if (seq[cmp] == seq[cmp+len-k]){
						// do nothing
					}else{
						equal = false;
						break;
					}
				}
				if (equal){
					store[seq] = k;
					flag = true;
					break;
				}
			}
			if (!flag) store[seq] = 0;
			cout << store[seq] << endl;
		}
	}
}