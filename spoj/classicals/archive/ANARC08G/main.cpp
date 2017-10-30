#include <bits/stdc++.h>

using namespace std;

int **mat;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int game = 1;
  cin >> n;
  while(n){
    mat = new int*[n];
    for(int i = 0; i < n; i++) mat[i] = new int[n];
    int total = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++){
        cin >> mat[i][j];
        total += mat[i][j];
      }
    int node[n];
    fill_n(node, n, 0);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++){
        node[i] -= mat[i][j];
        node[j] += mat[i][j];
      }
    int ans = 0;
    for(int i = 0; i < n; i++)
      if(node[i] < 0) ans += abs(node[i]);
    cout << game++ << ". " << total << " " << ans << endl;
    delete[] mat;
    cin >> n
  }
}

