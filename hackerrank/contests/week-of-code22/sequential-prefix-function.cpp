/*input
10
+ 2
+ 6
+ 2
-
-
-
+ 3
+ 6
+ 1
+ 3
*/

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

void print(vi a, int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << "  ";
	}
	cout << endl;
}
void print(vi a){
	for (int x: a){
		cout << x << " ";
	}
	cout << endl;
}

int main(void){
	ios::sync_with_stdio(false);
	int n, x;
	char sign;
	cin >> n;
	vi seq;
	vi lps(200001,0);
	int i = 0;
	for (int q = 0; q < n; q++){
		cin >> sign;
		if (sign == '+'){
			cin >> x;
			seq.pb(x);
			if (seq.size() < 2){
				cout << 0 << endl;
				i++;
			}else{
				int j = lps[i-1];
				// cout << "Initial j is " << j << endl;
				while (true){
					// cout << "Next j is " << j << " and i is " << i << endl;
					if (seq[j] == seq[i]){
						lps[i] = ++j;
						break;
					}else{
						if (j <= 0) break;
						j = lps[j-1];
					}
				}
				cout << lps[i++] << endl;
			}
		}else{
			// cout << "popback i: " << i << endl;
			if (!seq.empty()){
				lps[i-1] = 0;
				seq.pop_back();
				i--;
				cout << lps[i-1] << endl;
			}else{
				cout << 0 << endl;
			}
		}
		// cout << "Seq: "; print(seq);
		// cout << "lps: "; print(lps, 10);
	}
}
