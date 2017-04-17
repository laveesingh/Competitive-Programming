#include <iostream>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int mat[n][n];
    int ones = 0;
    for(int i = 0; i < n; i += 1)
      for(int j = 0; j < n; j += 1){
        cin >> mat[i][j];
        if(mat[i][j] == 1)
          ones++;
      }
    ones -= n;
    int band = 0;
    for(int i = 1; i < n; i++){
      if(ones > 0){
        band++;
        ones -= 2*(n-i);
      }else{
        break;
      }
    }
    cout << band << endl;
  }
}
