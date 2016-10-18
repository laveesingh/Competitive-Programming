#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, m;
  cin >> n >> m;
  int a[m][n];
  for(int i = 0; i < n; i += 1){
    cin >> a[0][i];
  }
  for(int i = 1; i < m; i += 1){
    for(int j = 0; j < n-1; j += 1){
      a[i][j] = a[i-1][j]^a[i-1][j+1];
    }
    a[i][n-1] = a[i-1][n-1]^a[i-1][0];
  }
  
  for(int j = 0; j < m; j += 1){
		for(int i = 0; i < n; i += 1)
			cout << a[j][i] << " ";
  
		  cout << endl;
		 }
}
