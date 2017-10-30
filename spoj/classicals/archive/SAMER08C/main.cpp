#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  while(n != 0 && m != 0){
    int mat[n][m];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) cin >> mat[i][j];
    for(int i = 0; i < n; i++)
      for(int j = 1; j < m; j++){
        mat[i][j] = max(mat[i][j-1], (j>1? mat[i][j-2]: 0) + mat[i][j]);
      }
    for(int i = 1; i < n; i++){
      mat[i][m-1] = max(mat[i-1][m-1], (i>1? mat[i-2][m-1]: 0) + mat[i][m-1]);
    }
    cout << mat[n-1][m-1] << endl;
    cin >> n >> m;
  }
}

