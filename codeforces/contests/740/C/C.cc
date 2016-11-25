#include <bits/stdc++.h>

using namespace std;

int main(void){
 int n, m, x, y;
 cin >> n >> m;
 int len = n;
 for(int i = 0; i < m; i += 1){
 	cin >> x >> y;
 	len = min(len, y-x+1);
 }
 cout << len << endl;
 for(int i = 0; i < n; i+=1){
 	cout << (i%len) << " ";
 }
 cout << endl;
}
